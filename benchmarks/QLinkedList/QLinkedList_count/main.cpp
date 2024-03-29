// QLinkedList::size
#include <iostream>
#include <QLinkedList>
#include <cassert>
using namespace std;

int main ()
{
  QLinkedList<int> myints;
  cout << "0. size: " << (int) myints.size() << endl;
  assert(myints.count() == 0);
  for (int i=0; i<10; i++) myints.push_back(i);
  cout << "1. size: " << (int) myints.size() << endl;
  assert(myints.count() == 10);
  myints.insert (myints.begin(),10);
  cout << "2. size: " << (int) myints.size() << endl;
  assert(myints.count() == 11);
  myints.pop_back();
  cout << "3. size: " << (int) myints.size() << endl;
  assert(myints.count() == 10);
  return 0;
}
