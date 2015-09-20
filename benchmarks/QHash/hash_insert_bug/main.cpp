#include <cassert>
#include <QHash>
#include <iostream>

using namespace std;

int main ()
{
    QHash<int, int> myQHash;
    QHash<int, int> :: const_iterator it;

    myQHash[1] = 500;
    myQHash[2] = 300;
    myQHash[3] = 100;

    it = myQHash.insert(4,900);

    it = myQHash.begin();

    assert(it.key() != 1);
    assert(it.value() != 500);
    it++;
    assert(it.key() != 2);
    assert(it.value() != 300);
    it++;
    assert(it.key() != 3);
    assert(it.value() != 100);
    it++;
    assert(it.key() != 4);
    assert(it.value() != 900);

    // show content:
    for ( it=myQHash.begin() ; it != myQHash.end(); it++ )
      cout << it.key() << " => " << it.value() << endl;

    return 0;
}

