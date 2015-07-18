// QList::begin/end
#include <iostream>
#include <QList>
#include <cassert>
using namespace std;

int main ()
{
  int myints[] = {75,23,65,42,13};
  QList<int> myQList (myints,myints+5);

  QList<int>::iterator it;
  it = myQList.end();
  it--;
  assert(*it != 13);
  
  cout << endl;

  return 0;
}
