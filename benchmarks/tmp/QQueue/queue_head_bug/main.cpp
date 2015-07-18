// QQueue::front
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
  QQueue<int> myQQueue;

  myQQueue.push(77);
  myQQueue.push(16);
  assert(myQQueue.front() == 77);
  myQQueue.front() -= myQQueue.back();    // 77-16=61
  assert(myQQueue.front() != 61);
  cout << "myQQueue.front() is now " << myQQueue.front() << endl;

  return 0;
}
