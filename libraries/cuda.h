#ifndef _CUDA_H
#define _CUDA_H	1

#include <stddef.h>
#include <cstdlib>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "vector_types.h"
#include "device_launch_parameters.h"

#include <new>

	/*verify_kernel()*/
typedef void* (*voidFunction_no_params)();
typedef void* (*voidFunction_one)(int* arg);
typedef void* (*voidFunction_two)(int* arg, int* arg2);
typedef void* (*voidFunction_three)(int* arg, int* arg2, int* arg3);

	/*verify_kernel_f()*/
typedef void* (*voidFunction_float)(float* arg1);
typedef void* (*voidFunction_ffloat)(float* arg1, float arg2);

	/*verify_kernel_intt()*/
typedef void* (*voidFunction_intt)(int* arg1, int arg2);

 	 /*verify_kernel_fuintt*/
typedef void* (*voidFunction_fuintt)(float* arg1, unsigned int arg2,
		unsigned int arg3);
typedef void* (*voidFunction_fuint)(float* arg1, unsigned int arg2);

	/*verify_kernel_three_args_iuull*/
typedef void* (*voidFunction_iuull)(int* arg1, unsigned int* arg2,
		unsigned long long int* arg3);

	/*verify_kernel_ui*/
typedef void* (*voidFunction_one_ui)(unsigned int* arg);
typedef void* (*voidFunction_ui)(unsigned int* arg);

/**
 * Error codes
 */
typedef enum cudaError {
	/**
	 * The API call returned with no errors. In the case of query calls, this
	 * can also mean that the operation being queried is complete (see
	 * ::cuEventQuery() and ::cuStreamQuery()).
	 */
	CUDA_SUCCESS = 0, cudaSuccess = 0,

	/**
	 * This indicates that one or more of the parameters passed to the API call
	 * is not within an acceptable range of values.
	 */
	CUDA_ERROR_INVALID_VALUE = 1,

	/**
	 * The API call failed because it was unable to allocate enough memory to
	 * perform the requested operation.
	 */
	CUDA_ERROR_OUT_OF_MEMORY = 2,

	/**
	 * This indicates that the CUDA driver has not been initialized with
	 * ::cuInit() or that initialization has failed.
	 */
	CUDA_ERROR_NOT_INITIALIZED = 3,

	/**
	 * This indicates that the CUDA driver is in the process of shutting down.
	 */
	CUDA_ERROR_DEINITIALIZED = 4,

	/**
	 * This indicates profiler is not initialized for this run. This can
	 * happen when the application is running with external profiling tools
	 * like visual profiler.
	 */
	CUDA_ERROR_PROFILER_DISABLED = 5,

	/**
	 * \deprecated
	 * This error return is deprecated as of CUDA 5.0. It is no longer an error
	 * to attempt to enable/disable the profiling via ::cuProfilerStart or
	 * ::cuProfilerStop without initialization.
	 */
	CUDA_ERROR_PROFILER_NOT_INITIALIZED = 6,

	/**
	 * \deprecated
	 * This error return is deprecated as of CUDA 5.0. It is no longer an error
	 * to call cuProfilerStart() when profiling is already enabled.
	 */
	CUDA_ERROR_PROFILER_ALREADY_STARTED = 7,

	/**
	 * \deprecated
	 * This error return is deprecated as of CUDA 5.0. It is no longer an error
	 * to call cuProfilerStop() when profiling is already disabled.
	 */
	CUDA_ERROR_PROFILER_ALREADY_STOPPED = 8,

	/**
	 * This indicates that the device ordinal supplied by the user does not
	 * correspond to a valid CUDA device.
	 */
	cudaErrorInvalidDevice = 10,

	/*
	 * This indicates that a call tried to access an exclusive-thread device that is already in use by a different thread.
	 */
	cudaErrorDeviceAlreadyInUse = 54,

	/**
	 * This indicates that no CUDA-capable devices were detected by the installed
	 * CUDA driver.
	 */
	CUDA_ERROR_NO_DEVICE = 100,

	/**
	 * This indicates that the device ordinal supplied by the user does not
	 * correspond to a valid CUDA device.
	 */
	CUDA_ERROR_INVALID_DEVICE = 101,

	/**
	 * This indicates that the device kernel image is invalid. This can also
	 * indicate an invalid CUDA module.
	 */
	CUDA_ERROR_INVALID_IMAGE = 200,

	/**
	 * This most frequently indicates that there is no context bound to the
	 * current thread. This can also be returned if the context passed to an
	 * API call is not a valid handle (such as a context that has had
	 * ::cuCtxDestroy() invoked on it). This can also be returned if a user
	 * mixes different API versions (i.e. 3010 context with 3020 API calls).
	 * See ::cuCtxGetApiVersion() for more details.
	 */
	CUDA_ERROR_INVALID_CONTEXT = 201,

	/**
	 * This indicated that the context being supplied as a parameter to the
	 * API call was already the active context.
	 * \deprecated
	 * This error return is deprecated as of CUDA 3.2. It is no longer an
	 * error to attempt to push the active context via ::cuCtxPushCurrent().
	 */
	CUDA_ERROR_CONTEXT_ALREADY_CURRENT = 202,

	/**
	 * This indicates that a map or register operation has failed.
	 */
	CUDA_ERROR_MAP_FAILED = 205,

	/**
	 * This indicates that an unmap or unregister operation has failed.
	 */
	CUDA_ERROR_UNMAP_FAILED = 206,

	/**
	 * This indicates that the specified array is currently mapped and thus
	 * cannot be destroyed.
	 */
	CUDA_ERROR_ARRAY_IS_MAPPED = 207,

	/**
	 * This indicates that the resource is already mapped.
	 */
	CUDA_ERROR_ALREADY_MAPPED = 208,

	/**
	 * This indicates that there is no kernel image available that is suitable
	 * for the device. This can occur when a user specifies code generation
	 * options for a particular CUDA source file that do not include the
	 * corresponding device configuration.
	 */
	CUDA_ERROR_NO_BINARY_FOR_GPU = 209,

	/**
	 * This indicates that a resource has already been acquired.
	 */
	CUDA_ERROR_ALREADY_ACQUIRED = 210,

	/**
	 * This indicates that a resource is not mapped.
	 */
	CUDA_ERROR_NOT_MAPPED = 211,

	/**
	 * This indicates that a mapped resource is not available for access as an
	 * array.
	 */
	CUDA_ERROR_NOT_MAPPED_AS_ARRAY = 212,

	/**
	 * This indicates that a mapped resource is not available for access as a
	 * pointer.
	 */
	CUDA_ERROR_NOT_MAPPED_AS_POINTER = 213,

	/**
	 * This indicates that an uncorrectable ECC error was detected during
	 * execution.
	 */
	CUDA_ERROR_ECC_UNCORRECTABLE = 214,

	/**
	 * This indicates that the ::CUlimit passed to the API call is not
	 * supported by the active device.
	 */
	CUDA_ERROR_UNSUPPORTED_LIMIT = 215,

	/**
	 * This indicates that the ::CUcontext passed to the API call can
	 * only be bound to a single CPU thread at a time but is already
	 * bound to a CPU thread.
	 */
	CUDA_ERROR_CONTEXT_ALREADY_IN_USE = 216,

	/**
	 * This indicates that peer access is not supported across the given
	 * devices.
	 */
	CUDA_ERROR_PEER_ACCESS_UNSUPPORTED = 217,

	/**
	 * This indicates that a PTX JIT compilation failed.
	 */
	CUDA_ERROR_INVALID_PTX = 218,

	/**
	 * This indicates an error with OpenGL or DirectX context.
	 */
	CUDA_ERROR_INVALID_GRAPHICS_CONTEXT = 219,

	/**
	 * This indicates that the device kernel source is invalid.
	 */
	CUDA_ERROR_INVALID_SOURCE = 300,

	/**
	 * This indicates that the file specified was not found.
	 */
	CUDA_ERROR_FILE_NOT_FOUND = 301,

	/**
	 * This indicates that a link to a shared object failed to resolve.
	 */
	CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND = 302,

	/**
	 * This indicates that initialization of a shared object failed.
	 */
	CUDA_ERROR_SHARED_OBJECT_INIT_FAILED = 303,

	/**
	 * This indicates that an OS call failed.
	 */
	CUDA_ERROR_OPERATING_SYSTEM = 304,

	/**
	 * This indicates that a resource handle passed to the API call was not
	 * valid. Resource handles are opaque types like ::CUstream and ::CUevent.
	 */
	CUDA_ERROR_INVALID_HANDLE = 400,

	/**
	 * This indicates that a named symbol was not found. Examples of symbols
	 * are global/constant variable names, texture names, and surface names.
	 */
	CUDA_ERROR_NOT_FOUND = 500,

	/**
	 * This indicates that asynchronous operations issued previously have not
	 * completed yet. This result is not actually an error, but must be indicated
	 * differently than ::CUDA_SUCCESS (which indicates completion). Calls that
	 * may return this value include ::cuEventQuery() and ::cuStreamQuery().
	 */
	CUDA_ERROR_NOT_READY = 600,

	/**
	 * While executing a kernel, the device encountered a
	 * load or store instruction on an invalid memory address.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_ILLEGAL_ADDRESS = 700,

	/**
	 * This indicates that a launch did not occur because it did not have
	 * appropriate resources. This error usually indicates that the user has
	 * attempted to pass too many arguments to the device kernel, or the
	 * kernel launch specifies too many threads for the kernel's register
	 * count. Passing arguments of the wrong size (i.e. a 64-bit pointer
	 * when a 32-bit int is expected) is equivalent to passing too many
	 * arguments and can also result in this error.
	 */
	CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES = 701,

	/**
	 * This indicates that the device kernel took too long to execute. This can
	 * only occur if timeouts are enabled - see the device attribute
	 * ::CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT for more information. The
	 * context cannot be used (and must be destroyed similar to
	 * ::CUDA_ERROR_LAUNCH_FAILED). All existing device memory allocations from
	 * this context are invalid and must be reconstructed if the program is to
	 * continue using CUDA.
	 */
	CUDA_ERROR_LAUNCH_TIMEOUT = 702,

	/**
	 * This error indicates a kernel launch that uses an incompatible texturing
	 * mode.
	 */
	CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING = 703,

	/**
	 * This error indicates that a call to ::cuCtxEnablePeerAccess() is
	 * trying to re-enable peer access to a context which has already
	 * had peer access to it enabled.
	 */
	CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED = 704,

	/**
	 * This error indicates that ::cuCtxDisablePeerAccess() is
	 * trying to disable peer access which has not been enabled yet
	 * via ::cuCtxEnablePeerAccess().
	 */
	CUDA_ERROR_PEER_ACCESS_NOT_ENABLED = 705,

	/**
	 * This error indicates that the primary context for the specified device
	 * has already been initialized.
	 */
	CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE = 708,

	/**
	 * This error indicates that the context current to the calling thread
	 * has been destroyed using ::cuCtxDestroy, or is a primary context which
	 * has not yet been initialized.
	 */
	CUDA_ERROR_CONTEXT_IS_DESTROYED = 709,

	/**
	 * A device-side assert triggered during kernel execution. The context
	 * cannot be used anymore, and must be destroyed. All existing device
	 * memory allocations from this context are invalid and must be
	 * reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_ASSERT = 710,

	/**
	 * This error indicates that the hardware resources required to enable
	 * peer access have been exhausted for one or more of the devices
	 * passed to ::cuCtxEnablePeerAccess().
	 */
	CUDA_ERROR_TOO_MANY_PEERS = 711,

	/**
	 * This error indicates that the memory range passed to ::cuMemHostRegister()
	 * has already been registered.
	 */
	CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED = 712,

	/**
	 * This error indicates that the pointer passed to ::cuMemHostUnregister()
	 * does not correspond to any currently registered memory region.
	 */
	CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED = 713,

	/**
	 * While executing a kernel, the device encountered a stack error.
	 * This can be due to stack corruption or exceeding the stack size limit.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_HARDWARE_STACK_ERROR = 714,

	/**
	 * While executing a kernel, the device encountered an illegal instruction.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_ILLEGAL_INSTRUCTION = 715,

	/**
	 * While executing a kernel, the device encountered a load or store instruction
	 * on a memory address which is not aligned.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_MISALIGNED_ADDRESS = 716,

	/**
	 * While executing a kernel, the device encountered an instruction
	 * which can only operate on memory locations in certain address spaces
	 * (global, shared, or local), but was supplied a memory address not
	 * belonging to an allowed address space.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_INVALID_ADDRESS_SPACE = 717,

	/**
	 * While executing a kernel, the device program counter wrapped its address space.
	 * The context cannot be used, so it must be destroyed (and a new one should be created).
	 * All existing device memory allocations from this context are invalid
	 * and must be reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_INVALID_PC = 718,

	/**
	 * An exception occurred on the device while executing a kernel. Common
	 * causes include dereferencing an invalid device pointer and accessing
	 * out of bounds shared memory. The context cannot be used, so it must
	 * be destroyed (and a new one should be created). All existing device
	 * memory allocations from this context are invalid and must be
	 * reconstructed if the program is to continue using CUDA.
	 */
	CUDA_ERROR_LAUNCH_FAILED = 719,

	/**
	 * This error indicates that the attempted operation is not permitted.
	 */
	CUDA_ERROR_NOT_PERMITTED = 800,

	/**
	 * This error indicates that the attempted operation is not supported
	 * on the current system or device.
	 */
	CUDA_ERROR_NOT_SUPPORTED = 801,

	/**
	 * This indicates that an unknown internal error has occurred.
	 */
	CUDA_ERROR_UNKNOWN = 999
} CUresult;

typedef enum cudaError cudaError_t;

cudaError_t lastError;

////////////////////////////////////////////////////////////////////////////
//! Structure that represents the threads of CUDA.

typedef struct threadsList {
	pthread_t thread;
	struct threadsList* prox;
} threadsList_t;

threadsList_t *cudaThreadList = NULL;

void cudaInsertThread(pthread_t threadAux) {

	threadsList_t *newCudaThread;
	newCudaThread = (threadsList_t *) malloc(sizeof(threadsList_t));
	if (newCudaThread == NULL)
		exit(0);
	newCudaThread->thread = threadAux;
	newCudaThread->prox = NULL;

	if (cudaThreadList == NULL) {
		cudaThreadList = newCudaThread;
	} else {
		newCudaThread->prox = cudaThreadList;
		cudaThreadList = newCudaThread;
	}
}

cudaError_t cudaThreadSynchronize() {

	cudaError_t tmp;
	threadsList_t *node;

	//	if (cudaThreadList == NULL)
	//		return CUDA_ERROR_OUT_OF_MEMORY;

	while (cudaThreadList != NULL) {
		pthread_join(cudaThreadList->thread, NULL);
		node = cudaThreadList;
		cudaThreadList = cudaThreadList->prox;
		free(node);
	}
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

void __syncthreads() {

	cudaThreadSynchronize();

}

cudaError_t cudaMalloc(void ** devPtr, size_t size) {

	cudaError_t tmp;
	//pre-conditions
	__ESBMC_assert(size > 0, "Size to be allocated may not be less than zero");
	*devPtr = malloc(size);

	if (*devPtr == NULL) {
		tmp = CUDA_ERROR_OUT_OF_MEMORY;
		exit(1);
	} else {
		tmp = CUDA_SUCCESS;
	}

	//post-conditions
	//__ESBMC_assert(tmp == CUDA_SUCCESS, "Memory was not allocated");

	lastError = tmp;
	return tmp;
}

/*void verify_kernel_void(void *(*kernel)(void *), int blocks, int threads, void* arg)
 {
 unsigned int n_threads = blocks*threads;
 pthread_t thread[n_threads];
 int i = 0, tmp;

 for(i = 0;i < n_threads;i++){
 pthread_create(&thread[i], NULL, kernel, arg);
 }
 for(i = 0;i < n_threads;i++)
 pthread_join(thread[i], NULL);
 }*/

	/* verify_kernel() */
struct arg_struct_no_params {
	void* (*func)();
};

struct arg_struct {
	int *a;
	int *b;
	int *c;
	void* (*func)(int*, int*, int*);
};

struct arg_struct1 {
	int *a;
	void* (*func)(int*);
};

struct arg_struct2 {
	int *a;
	int *b;
	void* (*func)(int*, int*);
};

	/*verify_kernel_f()*/
struct arg_struct_float {
	float *a;
	void* (*func)(float*);
};

struct arg_struct_ffloat {
	float *a;
	float b;
	void* (*func)(float*, float);
};

	/*verify_kernel_intt()*/
struct arg_struct_intt {
	int *a;
	int b;
	void* (*func)(int*, int);
};

	/*verify_kernel_fuintt()*/

struct arg_struct_fuintt {
	float *a;
	unsigned int b;
	unsigned int c;
	void* (*func)(float*, unsigned int, unsigned int);
};

struct arg_struct_fuint {
	float *a;
	unsigned int b;
	void* (*func)(float*, unsigned int);
};

	/*verify_kernel_three_args_iuull()*/
struct arg_struct_iuull {
	int *a;
	unsigned int *b;
	unsigned long long int *c;
	void* (*func)(int*, unsigned int*, unsigned long long int*);
};

	/*verify_kernel_ui()*/
struct arg_struct1_ui {
	unsigned int *a;
	void* (*func)(unsigned int*);
};

typedef struct arg_struct_no_params Targ_no_params;
typedef struct arg_struct Targ;
typedef struct arg_struct1 Targ1;
typedef struct arg_struct2 Targ2;

typedef struct arg_struct_intt Targ_intt;

typedef struct arg_struct_float Targ_float;
typedef struct arg_struct_ffloat Targ_ffloat;

typedef struct arg_struct_fuintt Targ_fuintt;
typedef struct arg_struct_fuint Targ_fuint;

typedef struct arg_struct_iuull Targ_iuull;
typedef struct arg_struct1_ui Targ1_ui;

unsigned int n_threads;
pthread_t *threads_id;
Targ_no_params dev_no_params;
Targ dev_three;
Targ1 dev_one;
Targ2 dev_two;

Targ_intt dev_intt;

Targ_float dev_float;
Targ_ffloat dev_ffloat;

Targ_fuintt dev_fuintt;
Targ_fuint dev_fuint;

Targ_iuull dev_three_iuull;
Targ1_ui dev_ui;

 	 /*verify_kernel()*/
void *execute_kernel_no_params(void *args) {
	__ESBMC_atomic_begin();
	dev_no_params.func();
	__ESBMC_atomic_end();
	return NULL;
}

void *execute_kernel_one(void *args) {
	__ESBMC_atomic_begin();
	dev_one.func(dev_one.a);
	__ESBMC_atomic_end();
	return NULL;
}

void *execute_kernel_two(void *args) {
	__ESBMC_atomic_begin();
	dev_two.func(dev_two.a, dev_two.b);
	__ESBMC_atomic_end();
	return NULL;
}

void *execute_kernel_three(void *args) {
	__ESBMC_atomic_begin();
	dev_three.func(dev_three.a, dev_three.b, dev_three.c);
	__ESBMC_atomic_end();
	return NULL;
}

	/*verify_kernel_f()*/
void *execute_kernel_float(void *args) {
	__ESBMC_atomic_begin();
	dev_float.func(dev_float.a);
	__ESBMC_atomic_end();
	return NULL;
}

void *execute_kernel_ffloat(void *args) {
	__ESBMC_atomic_begin();
	dev_ffloat.func(dev_ffloat.a, dev_ffloat.b);
	__ESBMC_atomic_end();
	return NULL;
}

	/*verify_kernel_intt()*/
void *execute_kernel_intt(void *args) {
	__ESBMC_atomic_begin();
	dev_intt.func(dev_intt.a, dev_intt.b);
	__ESBMC_atomic_end();
	return NULL;
}

	/*verify_kernel_fuintt()*/
void *execute_kernel_fuintt(void *args) {
	__ESBMC_atomic_begin();
	dev_fuintt.func(dev_fuintt.a, dev_fuintt.b, dev_fuintt.c);
	__ESBMC_atomic_end();
	return NULL;
}

void *execute_kernel_fuint(void *args) {
	__ESBMC_atomic_begin();
	dev_fuint.func(dev_fuint.a, dev_fuint.b);
	__ESBMC_atomic_end();
	return NULL;
}

	/*verify_kernel_three_args_iuull()*/
void *execute_kernel_three_iuull(void *args) {
	__ESBMC_atomic_begin();
	dev_three_iuull.func(dev_three_iuull.a, dev_three_iuull.b,
			dev_three_iuull.c);
	__ESBMC_atomic_end();
	return NULL;
}
	/*verify_kernel_three_args_ui()*/
void *execute_kernel_ui(void *args) {
	__ESBMC_atomic_begin();
	dev_ui.func(dev_ui.a);
	__ESBMC_atomic_end();
	return NULL;
}
	/*verify_kernel()*/
void verify_kernel_no_params(void *(*kernel)(), int blocks, int threads) {
	__ESBMC_atomic_begin();
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_no_params.func = kernel;

	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_no_params, NULL);
		i++;
	}
	__ESBMC_atomic_end();
}

void verify_kernel_with_one_arg(void *(*kernel)(int*), int blocks, int threads,
		void* arg1) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_one.a = (int*) malloc(n_threads * sizeof(int));
	dev_one.a = (int*) arg1;
	dev_one.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_one, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

void verify_kernel_with_two_args(void *(*kernel)(int*, int*), int blocks,
		int threads, void* arg1, void* arg2) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_two.a = (int*) malloc(n_threads * sizeof(int));
	dev_two.b = (int*) malloc(n_threads * sizeof(int));
	dev_two.a = (int*) arg1;
	dev_two.b = (int*) arg2;
	dev_two.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_two, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

void verify_kernel_with_three_args(void *(*kernel)(int*, int*, int*),
		int blocks, int threads, void* arg1, void* arg2, void* arg3) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_three.a = (int*) malloc(n_threads * sizeof(int));
	dev_three.b = (int*) malloc(n_threads * sizeof(int));
	dev_three.c = (int*) malloc(n_threads * sizeof(int));

	dev_three.a = (int*) arg1;
	dev_three.b = (int*) arg2;
	dev_three.c = (int*) arg3;
	dev_three.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_three, NULL);
		i++;
	}
	__ESBMC_atomic_end();
}

	/*verify_kernel_f()*/
void verify_kernel_float(void *(*kernel)(float*), int blocks,
		int threads, void* arg1) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_float.a = (float*) malloc(n_threads * sizeof(float));

	dev_float.a = (float*) arg1;
	dev_float.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_float, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

void verify_kernel_ffloat(void *(*kernel)(float*, float), int blocks,
		int threads, void* arg1, float arg2) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_ffloat.a = (float*) malloc(n_threads * sizeof(float));

	dev_ffloat.a = (float*) arg1;
	dev_ffloat.b = arg2;
	dev_ffloat.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_ffloat, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

	/*verify_kernel_intt()*/
void verify_kernel__intt(void *(*kernel)(int*, int), int blocks, int threads,
		void* arg1, int arg2) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_intt.a = (int*) malloc(n_threads * sizeof(int));

	dev_intt.a = (int*) arg1;
	dev_intt.b = arg2;
	dev_intt.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_intt, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

	/*verify_kernel_fuintt()*/
void verify_kernel__fuintt(void *(*kernel)(float*, unsigned int, unsigned int),
		int blocks, int threads, void* arg1, unsigned int arg2,
		unsigned int arg3) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_fuintt.a = (float*) malloc(n_threads * sizeof(float));

	dev_fuintt.a = (float*) arg1;
	dev_fuintt.b = arg2;
	dev_fuintt.c = arg3;
	dev_fuintt.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_fuintt, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

void verify_kernel__fuint(void *(*kernel)(float*, unsigned int),
		int blocks, int threads, void* arg1, unsigned int arg2) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_fuint.a = (float*) malloc(n_threads * sizeof(float));

	dev_fuint.a = (float*) arg1;
	dev_fuint.b = arg2;
	dev_fuint.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_fuint, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}
	//where is void verify_kernel__fuint()?

	/*verify_kernel_three_args_iuull()*/
void verify_kernel_with_three_args_iuull(
		void *(*kernel)(int*, unsigned int*, unsigned long long int*),
		int blocks, int threads, void* arg1, void* arg2, void* arg3) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_three_iuull.a = (int*) malloc(n_threads * sizeof(int));
	dev_three_iuull.b = (unsigned int*) malloc(
			n_threads * sizeof(unsigned int));
	dev_three_iuull.c = (unsigned long long int*) malloc(
			n_threads * sizeof(unsigned long long int));

	dev_three_iuull.a = (int*) arg1;
	dev_three_iuull.b = (unsigned int*) arg2;
	dev_three_iuull.c = (unsigned long long int*) arg3;
	dev_three_iuull.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_three_iuull, NULL);
		i++;
	}
	__ESBMC_atomic_end();
}

	/*verify_kernel_three_args_ui()*/
void verify_kernel_one_ui(void *(*kernel)(unsigned int*), int blocks,
		int threads, void* arg1) {
	__ESBMC_atomic_begin();
	n_threads = blocks * threads;
	threads_id = (pthread_t *) malloc(GPU_threads * sizeof(pthread_t));

	dev_ui.a = (unsigned int*) malloc(n_threads * sizeof(unsigned int));
	dev_ui.a = (unsigned int*) arg1;
	dev_ui.func = kernel;

	unsigned int n_threads = blocks * threads;
	int i = 0, tmp;
	assignIndexes();
	while (i < GPU_threads) {
		pthread_create(&threads_id[i], NULL, execute_kernel_ui, NULL);
		i++;
	}

	__ESBMC_atomic_end();
}

	/************ TEMPLATES **********/
	/*verify_kernel()*/
template<class RET, class BLOCK, class THREAD>
void verify_kernel(RET *kernel, BLOCK blocks, THREAD threads) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_no_params((voidFunction_no_params) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

template<class RET, class BLOCK, class THREAD, class T1>
void verify_kernel(RET *kernel, BLOCK blocks, THREAD threads, T1 arg) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_with_one_arg((voidFunction_one) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

template<class RET, class BLOCK, class THREAD, class T1, class T2>
void verify_kernel(RET *kernel, BLOCK blocks, THREAD threads, T1 arg, T2 arg2) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_with_two_args((voidFunction_two) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, (void*) arg2);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

}
//__ESBMC_atomic_end();

template<class RET, class BLOCK, class THREAD, class T1, class T2, class T3>
void verify_kernel(RET *kernel, BLOCK blocks, THREAD threads, T1 arg, T2 arg2,
		T3 arg3) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_with_three_args((voidFunction_three) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, (void*) arg2,
			(void*) arg3);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

	/*verify_kernel_f()*/
template<class RET, class BLOCK, class THREAD, class T1, class T2>
void verify_kernel_f(RET *kernel, BLOCK blocks, THREAD threads, T1 arg,
		T2 arg2) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_ffloat((voidFunction_ffloat) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, arg2);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

template<class RET, class BLOCK, class THREAD, class T1>
void verify_kernel_f(RET *kernel, BLOCK blocks, THREAD threads, T1 arg) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_float((voidFunction_float) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}
	/*verify_kernel_intt()*/
template<class RET, class BLOCK, class THREAD, class T1, class T2>
void verify_kernel_intt(RET *kernel, BLOCK blocks, THREAD threads, T1 arg,
		T2 arg2) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel__intt((voidFunction_intt) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, arg2);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

	/*verify_kernel_fuintt()*/
template<class RET, class BLOCK, class THREAD, class T1, class T2, class T3>
void verify_kernel_fuintt(RET *kernel, BLOCK blocks, THREAD threads, T1 arg,
		T2 arg2, T3 arg3) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel__fuintt((voidFunction_fuintt) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, arg2, arg3);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

template<class RET, class BLOCK, class THREAD, class T1, class T2>
void verify_kernel_fuint(RET *kernel, BLOCK blocks, THREAD threads, T1 arg,
		T2 arg2) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel__fuint((voidFunction_fuint) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, arg2);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

/*verify_kernel__three_args_iuull()*/
template<class RET, class BLOCK, class THREAD, class T1, class T2, class T3>
void verify_kernel_three_args_iuull(RET *kernel, BLOCK blocks, THREAD threads,
		T1 arg, T2 arg2, T3 arg3) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_with_three_args_iuull((voidFunction_iuull) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg, (void*) arg2,
			(void*) arg3);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

	/*verify_kernel_ui()*/
template<class RET, class BLOCK, class THREAD, class T1>
void verify_kernel_ui(RET *kernel, BLOCK blocks, THREAD threads, T1 arg) {
	//__ESBMC_atomic_begin();
	gridDim = dim3(blocks);
	blockDim = dim3(threads);

	verify_kernel_one_ui((voidFunction_one_ui) kernel,
			gridDim.x * gridDim.y * gridDim.z,
			blockDim.x * blockDim.y * blockDim.z, (void*) arg);

	int i = 0;
	for (i = 0; i < GPU_threads; i++)
		pthread_join(threads_id[i], NULL);

	//__ESBMC_atomic_end();
}

#if 0

void verify_kernel_with_one_arg_void(void *(*kernel)(void *), int blocks, int threads, void* arg)
{
	unsigned int n_threads = blocks*threads;
	pthread_t thread[n_threads];
	int i = 0;
	unsigned int tmp;
	__ESBMC_assume(tmp < n_threads);
	while (i < tmp)
	{
		pthread_create(&thread[i], NULL, kernel, arg);
		cudaInsertThread(thread[i]);
		i++;
	}
}
void verify_kernel_with_two_args_void(void *(*kernel)(void *), int blocks, int threads, void* arg1, void* arg2)
{
	int n_threads;
	n_threads = blocks*threads;
	pthread_t thread[n_threads];
	int i;
	for(i = 0; i < n_threads;i++) {
		pthread_create_with_two_args(&thread[i], NULL, kernel, arg1, arg2);
		cudaInsertThread(thread[i]);
	}
}
void verify_kernel_with_three_args_void(void *(*kernel)(void *), int blocks, int threads, void* arg1, void* arg2, void* arg3)
{
	int n_threads;
	n_threads = blocks*threads;
	pthread_t thread[n_threads];
	int i;
	for(i = 0; i < n_threads;i++) {
		pthread_create_with_three_arg(&thread[i], NULL, kernel, arg1, arg2, arg3);
		cudaInsertThread(thread[i]);
	}
}

template<class RET,class BLOCK, class THREAD, class T1>
void verify_kernel_with_one_arg(RET *kernel, BLOCK blocks, THREAD threads, T1 arg)
{
	gridDim = dim3( blocks );
	blockDim = dim3( threads);

	verify_kernel_with_one_arg_void(
			(voidFunction_t)kernel,
			gridDim.x*gridDim.y*gridDim.z,
			blockDim.x*blockDim.y*blockDim.z,
			(void*)arg);
}
template<class RET,class BLOCK, class THREAD, class T1, class T2>
void verify_kernel_with_two_args(RET *kernel, BLOCK blocks, THREAD threads, T1 arg1, T2 arg2)
{
	gridDim = dim3( blocks );
	blockDim = dim3( threads);

	verify_kernel_with_two_args_void(
			(voidFunction_t)kernel,
			gridDim.x*gridDim.y*gridDim.z,
			blockDim.x*blockDim.y*blockDim.z,
			(void*)arg1,
			(void*)arg2);
}

template<class RET,class BLOCK, class THREAD, class T1, class T2, class T3>
void verify_kernel_with_three_args(RET *kernel, BLOCK blocks, THREAD threads, T1 arg1, T2 arg2, T3 arg3)
{
	gridDim = dim3( blocks );
	blockDim = dim3( threads);

	verify_kernel_with_three_args_void(
			(voidFunction_t)kernel,
			gridDim.x*gridDim.y*gridDim.z,
			blockDim.x*blockDim.y*blockDim.z,
			(void*)arg1,
			(void*)arg2,
			(void*)arg3);
}

#endif

threadsList_t *cudaThreadList = NULL;

cudaError_t cudaFree(void *devPtr) {
	free(devPtr);
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

extern __device__  __cudart_builtin__ cudaError_t CUDARTAPI cudaDeviceGetAttribute(
		int *value, enum cudaDeviceAttr attr, int device) {
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

cudaError_t cudaDeviceGetLimit(int device) {
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

cudaError_t cudaDeviceGetCacheConfig(int device) {
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

cudaError_t cudaDeviceGetSharedMemConfig(int device) {
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

cudaError_t cudaPeekAtLastError(int device) {
	lastError = CUDA_SUCCESS;
	return CUDA_SUCCESS;
}

#endif	/* cuda.h */
