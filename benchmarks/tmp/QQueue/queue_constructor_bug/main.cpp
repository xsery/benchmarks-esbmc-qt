// constructing QQueues
#include <iostream>
#include <QQueue>
#include <cassert>
using namespace std;

int main ()
{
    QQueue<int> QQueue;
    QQueue.enQQueue(1);
    QQueue.enQQueue(2);
    QQueue.enQQueue(3);
    while (!QQueue.isEmpty())
        cout << QQueue.deQQueue() << endl;
    assert(!QQueue.isEmpty());
  return 0;
}
