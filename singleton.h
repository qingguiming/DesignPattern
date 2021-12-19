#ifndef SINGLETON_H
#define SINGLETON_H
#include <mutex>

class SingletonA
{

public:
    static SingletonA* getInstance();

private:
    SingletonA()
    {

    }
    static SingletonA *pSingletonA;
    static std::mutex _mutex;
};

SingletonA* SingletonA::pSingletonA = nullptr;
std::mutex SingletonA::_mutex;
SingletonA* SingletonA::getInstance()
{
    if(pSingletonA == nullptr)
    {
        SingletonA::_mutex.lock();
        if(pSingletonA == nullptr)
        {
            pSingletonA = new SingletonA();
        }
        SingletonA::_mutex.unlock();
    }
    return pSingletonA;
}

class SingletonB
{
public:
    static SingletonB* getInstance();

private:
    SingletonB()
    {
        printf("SingletonB %p \n",this);
    }
    static SingletonB *pSingletonB;

};

SingletonB* SingletonB::pSingletonB = nullptr;

std::once_flag gOnceFlag;

SingletonB* SingletonB::getInstance()
{
    std::call_once(gOnceFlag,[](){
        pSingletonB = new SingletonB();

    });
    return pSingletonB;
}


#endif // SINGLETON_H
