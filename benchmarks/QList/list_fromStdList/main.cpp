#include <iostream>
#include <QList>
#include <list>
#include <cassert>
using namespace std;

int main ()
{
    list<double> stdlist;
    stdlist.push_back(1.2);
    stdlist.push_back(0.5);
    stdlist.push_back(3.14);
    
    QList<double> list = QList<double>::fromStdList(stdlist);
  return 0;
}
