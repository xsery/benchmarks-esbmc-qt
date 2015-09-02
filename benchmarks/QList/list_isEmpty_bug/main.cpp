#include <iostream>
#include <QList>
#include <QString>
#include <cassert>
using namespace std;

int main ()
{
    QList<QString> first;
    first.append("A");
    assert(first.isEmpty());
  return 0;
}
