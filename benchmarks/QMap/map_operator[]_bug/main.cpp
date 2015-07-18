// accessing QMapped values
#include <iostream>
#include <QMap>
#include <string>
#include <cassert>
using namespace std;

int main ()
{
  QMap<char,string> myQMap;

  myQMap['a']="an element";
  myQMap['b']="another element";
  myQMap['c']=myQMap['b'];

  cout << "myQMap['a'] is " << myQMap['a'] << endl;
  cout << "myQMap['b'] is " << myQMap['b'] << endl;
  cout << "myQMap['c'] is " << myQMap['c'] << endl;
  cout << "myQMap['d'] is " << myQMap['d'] << endl;
  
  assert(myQMap['a']=="an element");
  assert(myQMap['b']=="another element");
  assert(myQMap['c']!=myQMap['b']);
  assert(myQMap['d']!=string());

  cout << "myQMap now contains " << (int) myQMap.size() << " elements." << endl;

  return 0;
}
