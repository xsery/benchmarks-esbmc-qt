// QQueue::push/pop
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
  QQueue<int> myQQueue;
  int myint;

  cout << "Please enter some integers (enter 0 to end):\n";
  int i;
  for(i = 0;i < 5;i++)
  	myQQueue.push(i);

  cout << "myQQueue contains: ";
  while (!myQQueue.isEmpty())
  {
  	assert(myQQueue.front() == 5-i--);//cout << " " << myQQueue.front()<< i-- << endl;
  	myQQueue.pop();
  }

  return 0;
}
