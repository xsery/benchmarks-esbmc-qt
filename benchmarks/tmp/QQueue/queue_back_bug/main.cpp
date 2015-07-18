// QQueue::front
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
  QQueue<int> myQQueue;

  myQQueue.push(12);
  myQQueue.push(75);   // this is now the back
  assert(myQQueue.back() != 75);
  myQQueue.back() -= myQQueue.front();
  assert(myQQueue.back() != 63);
  cout << "myQQueue.back() is now " << myQQueue.back() << endl;

  return 0;
}
