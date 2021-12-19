#ifndef STRATEGYPATTERN_H
#define STRATEGYPATTERN_H
#include <iostream>
using namespace std;
//策略模式
/***

策略模式针对一组算法，将每一个算法封装到具有共同接口的独立的类中，从而使得它们可以相互替换。
策略模式使得 算法可以在不影响到客户端的情况下发生变化。策略模式把行为和环境分开。
环境类负责维持和查询行为类，各种算法在具体的策略类中提供 。
由于算法和环境独立开来，算法的增减，修改都不会影响到环境和客户端

(有点类似桥接模式、但是桥接模式主要用于各个模块的接口设计)


****/
//抽象接口
class ReplaceAlgorithm
{
public:
    virtual int Replace() = 0;
};
//三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
    int Replace()
    {
        cout<<"Least Recently Used replace algorithm"<<endl;
        return 1;
    }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
    int Replace()
    {
        cout<<"First in First out replace algorithm"<<endl;
        return 1;
    }
};
class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
    int Replace()
    {
        cout<<"Random replace algorithm"<<endl;
        return 1;

    }
};
enum RA {LRU, FIFO, RANDOM}; //标签
class Cache
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(enum RA ra)
    {
        if(ra == LRU)
            m_ra = new LRU_ReplaceAlgorithm();
        else if(ra == FIFO)
            m_ra = new FIFO_ReplaceAlgorithm();
        else if(ra == RANDOM)
            m_ra = new Random_ReplaceAlgorithm();
        else
            m_ra = NULL;
    }
    ~Cache() { delete m_ra; }
    void Replace() { m_ra->Replace(); }
};

#endif // STRATEGYPATTERN_H
