#ifndef _CUDA_RUNTIME_API_H
#define _CUDA_RUNTIME_API_H	1

#include <stddef.h>
#include <stdio.h>
#include <driver_types.h>
#include "cuda.h"
#include "host_defines.h"
#include "builtin_types.h"
#include "cuda_device_runtime_api.h"

/** \cond impl_private */
#if !defined(__dv)

#if defined(__cplusplus)

#define __dv(v)

#else /* __cplusplus */

#define __dv(v)

#endif /* __cplusplus */

#endif /* !__dv */
/** \endcond impl_private */

#if !defined(__CUDA_ARCH__) || (__CUDA_ARCH__ >= 350)   /** Visible to SM>=3.5 and "__host__ __device__" only **/

#define CUDART_DEVICE __device__

#else

#define CUDART_DEVICE

#endif /** CUDART_DEVICE */


cudaError_t __cudaMemcpy(void *dst, const void *src,
		size_t count, enum cudaMemcpyKind kind)
{
	char *cdst = (char *) dst;
	const char *csrc = (const char *)src;
	int numbytes = count/(sizeof(char));
	for (int i = 0; i < numbytes; i++)
		cdst[i] = csrc[numbytes - i - 1];

	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

template<class T1, class T2>
cudaError_t cudaMemcpy(T1 dst, T2 src, size_t count, enum cudaMemcpyKind kind)
{
	return __cudaMemcpy (dst,src,count, kind);
}

char* cudaGetErrorString(cudaError_t error){

	char* erroReturn;

	switch (error){

		case 0: return "CUDA_SUCCESS"; break;
		case 1:	return "CUDA_ERROR_INVALID_VALUE"; break;
		case 2: return "CUDA_ERROR_OUT_OF_MEMORY"; break;
		case 3:	return "CUDA_ERROR_NOT_INITIALIZED"; break;
		case 4:	return "CUDA_ERROR_DEINITIALIZED"; break;
		case 5:	return "CUDA_ERROR_PROFILER_DISABLED"; break;
		case 6: return "CUDA_ERROR_PROFILER_NOT_INITIALIZED"; break;
		case 7: return "CUDA_ERROR_PROFILER_ALREADY_STARTED"; break;
		case 8: return "CUDA_ERROR_PROFILER_ALREADY_STOPPED"; break;
		case 100: return "CUDA_ERROR_NO_DEVICE"; break;
		case 101: return "CUDA_ERROR_INVALID_DEVICE"; break;
		case 200: return "CUDA_ERROR_INVALID_IMAGE"; break;
		case 201: return "CUDA_ERROR_INVALID_CONTEXT"; break;
		case 202: return "CUDA_ERROR_CONTEXT_ALREADY_CURRENT"; break;
		case 205: return "CUDA_ERROR_MAP_FAILED"; break;
		case 206: return "CUDA_ERROR_UNMAP_FAILED"; break;
		case 207: return "CUDA_ERROR_ARRAY_IS_MAPPED"; break;
		case 208: return "CUDA_ERROR_ALREADY_MAPPED"; break;
		case 209: return "CUDA_ERROR_NO_BINARY_FOR_GPU"; break;
		case 210: return "CUDA_ERROR_ALREADY_ACQUIRED"; break;
		case 211: return "CUDA_ERROR_NOT_MAPPED"; break;
		case 212: return "CUDA_ERROR_NOT_MAPPED_AS_ARRAY"; break;
		case 213: return "CUDA_ERROR_NOT_MAPPED_AS_POINTER"; break;
		case 214: return "CUDA_ERROR_ECC_UNCORRECTABLE"; break;
		case 215: return "CUDA_ERROR_UNSUPPORTED_LIMIT"; break;
		case 216: return "CUDA_ERROR_CONTEXT_ALREADY_IN_USE"; break;
		case 217: return "CUDA_ERROR_PEER_ACCESS_UNSUPPORTED"; break;
		case 218: return "CUDA_ERROR_INVALID_PTX"; break;
		case 219: return "CUDA_ERROR_INVALID_GRAPHICS_CONTEXT"; break;
		case 300: return "CUDA_ERROR_INVALID_SOURCE"; break;
		case 301: return "CUDA_ERROR_FILE_NOT_FOUND"; break;
		case 302: return "CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND"; break;
		case 303: return "CUDA_ERROR_SHARED_OBJECT_INIT_FAILED"; break;
		case 304: return "CUDA_ERROR_OPERATING_SYSTEM"; break;
		case 400: return "CUDA_ERROR_INVALID_HANDLE"; break;
		case 500: return "CUDA_ERROR_NOT_FOUND"; break;
		case 600: return "CUDA_ERROR_NOT_READY"; break;
		case 700: return "CUDA_ERROR_ILLEGAL_ADDRESS"; break;
		case 701: return "CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES"; break;
		case 702: return "CUDA_ERROR_LAUNCH_TIMEOUT"; break;
		case 703: return "CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING"; break;
		case 704: return "CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED"; break;
		case 705: return "CUDA_ERROR_PEER_ACCESS_NOT_ENABLED"; break;
		case 708: return "CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE"; break;
		case 709: return "CUDA_ERROR_CONTEXT_IS_DESTROYED"; break;
		case 710: return "CUDA_ERROR_ASSERT"; break;
		case 711: return "CUDA_ERROR_TOO_MANY_PEERS"; break;
		case 712: return "CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED"; break;
		case 713: return "CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED"; break;
		case 714: return "CUDA_ERROR_HARDWARE_STACK_ERROR"; break;
		case 715: return "CUDA_ERROR_ILLEGAL_INSTRUCTION"; break;
		case 716: return "CUDA_ERROR_MISALIGNED_ADDRESS"; break;
		case 717: return "CUDA_ERROR_INVALID_ADDRESS_SPACE"; break;
		case 718: return "CUDA_ERROR_INVALID_PC"; break;
		case 719: return "CUDA_ERROR_LAUNCH_FAILED"; break;
		case 800: return "CUDA_ERROR_NOT_PERMITTED"; break;
		case 801: return "CUDA_ERROR_NOT_SUPPORTED"; break;
		case 999: return "CUDA_ERROR_UNKNOWN"; break;
		default: return "CUDA_SUCCESS";
	}
}

////////////////////////////////////////////////////////////////////////////
//!  Structure that represents the devices of CUDA.

//Struct to Device - OK
typedef struct cudaDevicesList {
	int id;
	int active;
	struct cudaDeviceProp deviceProp;
	struct cudaDevicesList* prox;
} cudaDeviceList_t;

cudaDeviceList_t *cudaDeviceList = NULL;

//Insert a device
void cudaDeviceInsert(int device){

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	//Verifies that the device exists in the list
	while(auxDevice!=NULL){

		if(auxDevice->id==device){
			//printf("\nDevice existing");
			//return 0;
		}
		auxDevice = auxDevice->prox;
	}

	//Insert new device
	cudaDeviceList_t *newCudaDevice;

	newCudaDevice = (cudaDeviceList_t *) malloc(sizeof(cudaDeviceList_t));
	if (newCudaDevice == NULL)
		exit(0);

	newCudaDevice->id = device;
	newCudaDevice->active = 0;
	//newCudaDevice->deviceProp.regsPerBlock = var; //Insert fields to deviceProp
	newCudaDevice->prox = NULL;

	if(cudaDeviceList == NULL){
		cudaDeviceList = newCudaDevice;
	}else{
		newCudaDevice->prox = cudaDeviceList;
		cudaDeviceList = newCudaDevice;
	}

//	return 1;
}

//Searching for a device in the devices list
void cudaPrintDevice(){

	//printf("\n\n*** CUDA Device\n");

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){
		//printf("->Device: %d Active:%d\n",auxDevice->id,auxDevice->active);
		auxDevice = auxDevice->prox;
	}

}

//Searching for a device in the devices list
int searchCudaDevice(int device){

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){
		if(auxDevice->id==device){
			return 1;
		}else{
			auxDevice = auxDevice->prox;
		}
	}
	return 0;
}

//Checks whether the device is in use
int cudaDeviceActive(int device){

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){
		if(auxDevice->id==device){
			if(auxDevice->active==1){
				return 1;
			}else{
				return 0;
			}
		}
	}
	return 0;
}

//Start a device
int cudaDeviceStart(int device){

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){
		if(auxDevice->id==device){
			auxDevice->active = 1;
			return 1;
		}
		auxDevice = auxDevice->prox;
	}
	return 0;
}

// Choose a device to work
cudaError_t cudaSetDevice(int device){

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){ //Scroll through the list
		if(auxDevice->id==device){ //Checks if the device
			if(auxDevice->active==1){ //Verifies that the device is active
				return cudaErrorDeviceAlreadyInUse; //cudaErrorDeviceAlreadyInUse
				lastError = cudaErrorDeviceAlreadyInUse;
			}
			auxDevice->active=1;
			lastError = cudaSuccess;
			return cudaSuccess;
		}else
		auxDevice = auxDevice->prox;
	}
	//If not found, return cudaErrorInvalidDevice
	lastError = cudaErrorInvalidDevice;
	return cudaErrorInvalidDevice;
}

// Returns the number of compute-capable devices.
cudaError_t cudaGetDeviceCount(int* count){
/*
	cudaDeviceList_t *auxDevice = cudaDeviceList;
	int i;

	while(auxDevice!=NULL){
		i++;
		auxDevice = auxDevice->prox;
	}
 	 */
	lastError = cudaSuccess;
	return cudaSuccess;
}

//Destroy all allocations and reset all state on the current device in the current process.
cudaError_t cudaDeviceReset(){

	int tmp;
	threadsList_t *node;

	while(cudaThreadList != NULL){
//		pthread_exit(cudaThreadList->thread);
		node = cudaThreadList;
		cudaThreadList = cudaThreadList->prox;
		free(node);
	}

	lastError = cudaSuccess;
	return cudaSuccess;
}

/*
 *    Memory Management
 */
cudaError_t cudaMemcpyToSymbol(const void *symbol, const void *src, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyHostToDevice)){

	cudaError_t  out;

	out = __cudaMemcpy((void*)(symbol), (const void*)src, count, kind);

	lastError = out;
	return out;
}

cudaError_t cudaMemcpyFromSymbol(void *dst, const void *symbol, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToHost)){

	cudaError_t  out;

	out = __cudaMemcpy((void*) dst, (const void*)(symbol), count, kind);

	lastError = out;
	return out;
}

extern __host__ cudaError_t CUDARTAPI cudaSetDevice(int device);
//extern __device__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetDeviceCount(int *count);
//extern __host__ cudaError_t CUDARTAPI cudaDeviceReset(void);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);

extern cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device){

	struct cudaDeviceProp deviceChosen;

	int out;

	cudaDeviceList_t *auxDevice = cudaDeviceList;

	while(auxDevice!=NULL){
		if(auxDevice->id==device){
			deviceChosen = auxDevice->deviceProp;
			prop = &deviceChosen;
			return cudaSuccess;
		}
		auxDevice = auxDevice->prox;
	}

	return CUDA_ERROR_INVALID_VALUE;
}

cudaError_t cudaGetLastError(){

	return lastError;

}


//extern __host__ cudaError_t CUDARTAPI cudaMemset(void *devPtr, int value, size_t count);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaEventCreateWithFlags(cudaEvent_t *event, unsigned int flags);

//extern __host__ cudaError_t CUDARTAPI cudaHostAlloc(void **pHost, size_t size, unsigned int flags);

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*extern __host__ cudaError_t CUDARTAPI cudaDeviceReset(void);*/

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceSynchronize(void);

//extern __host__ cudaError_t CUDARTAPI cudaDeviceSetLimit(enum cudaLimit limit, size_t value);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetLimit(size_t *pValue, enum cudaLimit limit);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetCacheConfig(enum cudaFuncCache *pCacheConfig);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetStreamPriorityRange(int *leastPriority, int *greatestPriority);

//extern __host__ cudaError_t CUDARTAPI cudaDeviceSetCacheConfig(enum cudaFuncCache cacheConfig);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetSharedMemConfig(enum cudaSharedMemConfig *pConfig);

//extern __host__ cudaError_t CUDARTAPI cudaDeviceSetSharedMemConfig(enum cudaSharedMemConfig config);

extern __host__ cudaError_t CUDARTAPI cudaDeviceGetByPCIBusId(int *device, const char *pciBusId);

extern __host__ cudaError_t CUDARTAPI cudaDeviceGetPCIBusId(char *pciBusId, int len, int device);

//extern __host__ cudaError_t CUDARTAPI cudaIpcGetEventHandle(cudaIpcEventHandle_t *handle, cudaEvent_t event);

//extern __host__ cudaError_t CUDARTAPI cudaIpcOpenEventHandle(cudaEvent_t *event, cudaIpcEventHandle_t handle);


//extern __host__ cudaError_t CUDARTAPI cudaIpcGetMemHandle(cudaIpcMemHandle_t *handle, void *devPtr);

//extern __host__ cudaError_t CUDARTAPI cudaIpcOpenMemHandle(void **devPtr, cudaIpcMemHandle_t handle, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaIpcCloseMemHandle(void *devPtr);

extern __host__ cudaError_t CUDARTAPI cudaThreadExit(void);

//extern __host__ cudaError_t CUDARTAPI cudaThreadSynchronize(void);

//extern __host__ cudaError_t CUDARTAPI cudaThreadSetLimit(enum cudaLimit limit, size_t value);

//extern __host__ cudaError_t CUDARTAPI cudaThreadGetLimit(size_t *pValue, enum cudaLimit limit);

//extern __host__ cudaError_t CUDARTAPI cudaThreadGetCacheConfig(enum cudaFuncCache *pCacheConfig);

//extern __host__ cudaError_t CUDARTAPI cudaThreadSetCacheConfig(enum cudaFuncCache cacheConfig);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetLastError(void);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaPeekAtLastError(void);

extern __host__ __cudart_builtin__ const char* CUDARTAPI cudaGetErrorName(cudaError_t error);

extern __host__ __cudart_builtin__ const char* CUDARTAPI cudaGetErrorString(cudaError_t error);
/*extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetDeviceCount(int *count);*/

/*extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);*/

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetAttribute(int *value, enum cudaDeviceAttr attr, int device);

extern __host__ cudaError_t CUDARTAPI cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);

/*extern __host__ cudaError_t CUDARTAPI cudaSetDevice(int device);*/

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaGetDevice(int *device);

extern __host__ cudaError_t CUDARTAPI cudaSetValidDevices(int *device_arr, int len);

extern __host__ cudaError_t CUDARTAPI cudaSetDeviceFlags( unsigned int flags );

//extern __host__ cudaError_t CUDARTAPI cudaStreamCreate(cudaStream_t *pStream);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamCreateWithFlags(cudaStream_t *pStream, unsigned int flags);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamCreateWithPriority(cudaStream_t *pStream, unsigned int flags, int priority);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamGetPriority(cudaStream_t hStream, int *priority);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamGetFlags(cudaStream_t hStream, unsigned int *flags);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamDestroy(cudaStream_t stream);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned int flags);

#ifdef _WIN32
#define CUDART_CB __stdcall
#else
#define CUDART_CB
#endif

//typedef void (CUDART_CB *cudaStreamCallback_t)(cudaStream_t stream, cudaError_t status, void *userData);

//extern __host__ cudaError_t CUDARTAPI cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void *userData, unsigned int flags);

//extern __host__ cudaError_t CUDARTAPI cudaStreamSynchronize(cudaStream_t stream);

//extern __host__ cudaError_t CUDARTAPI cudaStreamQuery(cudaStream_t stream);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamAttachMemAsync(cudaStream_t stream, void *devPtr, size_t length, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaEventCreate(cudaEvent_t *event);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaEventCreateWithFlags(cudaEvent_t *event, unsigned int flags);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaEventRecord(cudaEvent_t event, cudaStream_t stream __dv(0));

extern __host__ cudaError_t CUDARTAPI cudaEventQuery(cudaEvent_t event);

extern __host__ cudaError_t CUDARTAPI cudaEventSynchronize(cudaEvent_t event);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaEventDestroy(cudaEvent_t event);

extern __host__ cudaError_t CUDARTAPI cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);

/** @} */ /* END CUDART_EVENT */

//extern __host__ cudaError_t CUDARTAPI cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem __dv(0), cudaStream_t stream __dv(0));

extern __host__ cudaError_t CUDARTAPI cudaSetupArgument(const void *arg, size_t size, size_t offset);

//extern __host__ cudaError_t CUDARTAPI cudaFuncSetCacheConfig(const void *func, enum cudaFuncCache cacheConfig);

//extern __host__ cudaError_t CUDARTAPI cudaFuncSetSharedMemConfig(const void *func, enum cudaSharedMemConfig config);

extern __host__ cudaError_t CUDARTAPI cudaLaunch(const void *func);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const void *func);

extern __host__ cudaError_t CUDARTAPI cudaSetDoubleForDevice(double *d);

extern __host__ cudaError_t CUDARTAPI cudaSetDoubleForHost(double *d);

/** @} */ /* END CUDART_EXECUTION */

#if CUDART_VERSION >= 6050

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, const void *func, int blockSize, size_t dynamicSMemSize);

/** @} */ /* END CUDA_OCCUPANCY */
#endif /* CUDART_VERSION >= 6050 */

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMallocManaged(void **devPtr, size_t size, unsigned int flags);


/*extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMalloc(void **devPtr, size_t size);*/

extern __host__ cudaError_t CUDARTAPI cudaMallocHost(void **ptr, size_t size);

extern __host__ cudaError_t CUDARTAPI cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);

//extern __host__ cudaError_t CUDARTAPI cudaMallocArray(cudaArray_t *array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height __dv(0), unsigned int flags __dv(0));

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaFree(void *devPtr);

extern __host__ cudaError_t CUDARTAPI cudaFreeHost(void *ptr);

//extern __host__ cudaError_t CUDARTAPI cudaFreeArray(cudaArray_t array);

//extern __host__ cudaError_t CUDARTAPI cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray);


extern __host__ cudaError_t CUDARTAPI cudaHostAlloc(void **pHost, size_t size, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaHostRegister(void *ptr, size_t size, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaHostUnregister(void *ptr);

extern __host__ cudaError_t CUDARTAPI cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaHostGetFlags(unsigned int *pFlags, void *pHost);

extern __host__ cudaError_t CUDARTAPI cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);

//extern __host__ cudaError_t CUDARTAPI cudaMalloc3DArray(cudaArray_t *array, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent, unsigned int flags __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMallocMipmappedArray(cudaMipmappedArray_t *mipmappedArray, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent, unsigned int numLevels, unsigned int flags __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaGetMipmappedArrayLevel(cudaArray_t *levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned int level);

extern __host__ cudaError_t CUDARTAPI cudaMemcpy3D(const struct cudaMemcpy3DParms *p);

extern __host__ cudaError_t CUDARTAPI cudaMemcpy3DPeer(const struct cudaMemcpy3DPeerParms *p);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy3DPeerAsync(const struct cudaMemcpy3DPeerParms *p, cudaStream_t stream __dv(0));

extern __host__ cudaError_t CUDARTAPI cudaMemGetInfo(size_t *free, size_t *total);

//extern __host__ cudaError_t CUDARTAPI cudaArrayGetInfo(struct cudaChannelFormatDesc *desc, struct cudaExtent *extent, unsigned int *flags, cudaArray_t array);

extern __host__ cudaError_t CUDARTAPI cudaMemcpyPeer(void *dst, int dstDevice, const void *src, int srcDevice, size_t count);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArray(void *dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToDevice));

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArray(void *dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind);

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToDevice));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbol(const void *symbol, const void *src, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyHostToDevice));


//extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbol(void *dst, const void *symbol, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToHost));

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));


//extern __host__ cudaError_t CUDARTAPI cudaMemcpyPeerAsync(void *dst, int dstDevice, const void *src, int srcDevice, size_t count, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync(void *dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync(const void *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync(void *dst, const void *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream __dv(0));


extern __host__ cudaError_t CUDARTAPI cudaMemset(void *devPtr, int value, size_t count);

extern __host__ cudaError_t CUDARTAPI cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);

extern __host__ cudaError_t CUDARTAPI cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemsetAsync(void *devPtr, int value, size_t count, cudaStream_t stream __dv(0));

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemset2DAsync(void *devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream __dv(0));

//extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemset3DAsync(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent, cudaStream_t stream __dv(0));

extern __host__ cudaError_t CUDARTAPI cudaGetSymbolAddress(void **devPtr, const void *symbol);

extern __host__ cudaError_t CUDARTAPI cudaGetSymbolSize(size_t *size, const void *symbol);

/** @} */ /* END CUDART_MEMORY */


extern __host__ cudaError_t CUDARTAPI cudaPointerGetAttributes(struct cudaPointerAttributes *attributes, const void *ptr);

/** @} */ /* END CUDART_UNIFIED */

extern __host__ cudaError_t CUDARTAPI cudaDeviceCanAccessPeer(int *canAccessPeer, int device, int peerDevice);

extern __host__ cudaError_t CUDARTAPI cudaDeviceEnablePeerAccess(int peerDevice, unsigned int flags);

extern __host__ cudaError_t CUDARTAPI cudaDeviceDisablePeerAccess(int peerDevice);

/** @} */ /* END CUDART_PEER */

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource);

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned int flags);

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsMapResources(int count, cudaGraphicsResource_t *resources, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t *resources, cudaStream_t stream __dv(0));

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsResourceGetMappedPointer(void **devPtr, size_t *size, cudaGraphicsResource_t resource);

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsSubResourceGetMappedArray(cudaArray_t *array, cudaGraphicsResource_t resource, unsigned int arrayIndex, unsigned int mipLevel);

//extern __host__ cudaError_t CUDARTAPI cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t *mipmappedArray, cudaGraphicsResource_t resource);

/** @} */ /* END CUDART_INTEROP */

//extern __host__ cudaError_t CUDARTAPI cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, cudaArray_const_t array);

//extern __host__ struct cudaChannelFormatDesc CUDARTAPI cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);


extern __host__ cudaError_t CUDARTAPI cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size __dv(UINT_MAX));

extern __host__ cudaError_t CUDARTAPI cudaBindTexture2D(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t width, size_t height, size_t pitch);

//extern __host__ cudaError_t CUDARTAPI cudaBindTextureToArray(const struct textureReference *texref, cudaArray_const_t array, const struct cudaChannelFormatDesc *desc);

//extern __host__ cudaError_t CUDARTAPI cudaBindTextureToMipmappedArray(const struct textureReference *texref, cudaMipmappedArray_const_t mipmappedArray, const struct cudaChannelFormatDesc *desc);

extern __host__ cudaError_t CUDARTAPI cudaUnbindTexture(const struct textureReference *texref);

extern __host__ cudaError_t CUDARTAPI cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref);

extern __host__ cudaError_t CUDARTAPI cudaGetTextureReference(const struct textureReference **texref, const void *symbol);

/** @} */ /* END CUDART_TEXTURE */

//extern __host__ cudaError_t CUDARTAPI cudaBindSurfaceToArray(const struct surfaceReference *surfref, cudaArray_const_t array, const struct cudaChannelFormatDesc *desc);

extern __host__ cudaError_t CUDARTAPI cudaGetSurfaceReference(const struct surfaceReference **surfref, const void *symbol);

/** @} */ /* END CUDART_SURFACE */

//extern __host__ cudaError_t CUDARTAPI cudaCreateTextureObject(cudaTextureObject_t *pTexObject, const struct cudaResourceDesc *pResDesc, const struct cudaTextureDesc *pTexDesc, const struct cudaResourceViewDesc *pResViewDesc);

//extern __host__ cudaError_t CUDARTAPI cudaDestroyTextureObject(cudaTextureObject_t texObject);

//extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectResourceDesc(struct cudaResourceDesc *pResDesc, cudaTextureObject_t texObject);

//extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectTextureDesc(struct cudaTextureDesc *pTexDesc, cudaTextureObject_t texObject);

//extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectResourceViewDesc(struct cudaResourceViewDesc *pResViewDesc, cudaTextureObject_t texObject);

/** @} */ /* END CUDART_TEXTURE_OBJECT */

//extern __host__ cudaError_t CUDARTAPI cudaCreateSurfaceObject(cudaSurfaceObject_t *pSurfObject, const struct cudaResourceDesc *pResDesc);

//extern __host__ cudaError_t CUDARTAPI cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject);

//extern __host__ cudaError_t CUDARTAPI cudaGetSurfaceObjectResourceDesc(struct cudaResourceDesc *pResDesc, cudaSurfaceObject_t surfObject);

/** @} */ /* END CUDART_SURFACE_OBJECT */

/**
 * \defgroup CUDART__VERSION Version Management
 *
 * @{
 */

extern __host__ cudaError_t CUDARTAPI cudaDriverGetVersion(int *driverVersion);

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaRuntimeGetVersion(int *runtimeVersion);

/** @} */ /* END CUDART__VERSION */

/** \cond impl_private */
//extern __host__ cudaError_t CUDARTAPI cudaGetExportTable(const void **ppExportTable, const cudaUUID_t *pExportTableId);
/** \endcond impl_private */

#if defined(__cplusplus)
}

#endif /* __cplusplus */

#undef __dv



#endif	/* cuda_runtime_api.h */

