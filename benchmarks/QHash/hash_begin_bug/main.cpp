#include <cassert>
#include <QHash>
#include <QString>
#include <iostream>

using namespace std;

int main ()
{
    QHash<QString, int> myQHash;
    QHash<QString, int> ::iterator it;
    string utf8_text;

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

    // show content:
    for ( it=myQHash.begin() ; it != myQHash.end(); it++ )
      utf8_text= it.key().toUtf8().constData();
      cout << utf8_text << " => " << it.value() << endl;

    return 0;
}
