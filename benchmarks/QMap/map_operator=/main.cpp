// assignment operator with QMaps
#include <iostream>
#include <QMap>
#include <cassert>
using namespace std;

int main ()
{
  QMap<char,int>first;
  QMap<char,int>second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  second = first;           //value() now contains 3 ints
  assert(second['x'] == 8);
  assert(second['y'] == 16);
  assert(second['z'] == 32);
  
  first = QMap<char,int>();  // andkey() is now empty
  assert(first.size() == 0);

  cout << "Size ofkey(): " << first.size() << endl;
  cout << "Size ofvalue(): " << second.size() << endl;
  return 0;
}
