#include <cassert>
#include <QHash>
#include <QString>

int main ()
{
    QHash<QString, int> myQHash;
    QHash<QString, int> ::iterator it;

    myQHash["abc"] = 500;
    myQHash["cde"] = 300;
    myQHash["fgh"] = 100;

    it = myQHash.begin();
    assert(it.key() != "abc");
    assert(it.value() != 500);
    it++;
    assert(it.key() != "cde");
    assert(it.value() != 300);
    it++;
    assert(it.key() != "fgh");
    assert(it.value() != 100);

    return 0;
}
