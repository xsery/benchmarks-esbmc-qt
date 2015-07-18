// QList::empty
#include <iostream>
#include <QList>
#include <cassert>
using namespace std;

int main ()
{
  QList<int> myQList;
  int sum (0);

  for (int i=1;i<=10;i++) myQList.push_back(i);

  assert(!myQList.empty());
  while (!myQList.empty())
  {
     sum += myQList.front();
     myQList.pop_front();
  }
  assert(!myQList.empty()||(myQList.size() != 0));
  cout << "total: " << sum << endl;
  
  return 0;
}
