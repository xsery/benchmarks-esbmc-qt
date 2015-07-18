// constructing QQueues
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
    QQueue<int> QQueue;
    QQueue.enqueue(1);
    QQueue.enqueue(2);
    QQueue.enqueue(3);
    while (!QQueue.isEmpty())
        cout << QQueue.dequeue() << endl;
    assert(!QQueue.isEmpty());
  return 0;
}
