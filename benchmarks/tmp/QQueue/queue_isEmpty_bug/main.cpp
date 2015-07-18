// QQueue::isEmpty
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
  QQueue<int> myQQueue;
  int sum (0);

  for (int i=1;i<=10;i++) myQQueue.push(i);

  while (!myQQueue.isEmpty())
  {
     sum += myQQueue.front();
     myQQueue.pop();
  }
  assert(!myQQueue.isEmpty());
  cout << "total: " << sum << endl;
  
  return 0;
}
