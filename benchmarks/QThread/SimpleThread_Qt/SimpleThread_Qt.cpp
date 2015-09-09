#include <QtCore>


#include <iostream>
using namespace std;

const int DataSize = 100000;

class Producer : public QThread
{
public:
    void run() Q_DECL_OVERRIDE
    {
        for (int i = 0; i < DataSize; ++i)
        {
            cout<<"PRODUCER\n";
        }

    }
};

class Consumer : public QThread
{
public:
    void run() Q_DECL_OVERRIDE
    {
        for (int i = 0; i < DataSize; ++i)
        {
            cout<<"CONSUMER\n";
        }
    }

};

int main()
{
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return 0;
}
