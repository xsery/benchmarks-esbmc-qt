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

    it = myQHash.cbegin();
    it++;
    it++;
    it++;

    assert(!(myQHash.contains(it.key())));

    return 0;
}

