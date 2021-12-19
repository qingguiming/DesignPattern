#ifndef DUTYLIST_H
#define DUTYLIST_H

//职责链模式

/*****

    责任链模式：在责任链模式中，很多对象由每一个对象对其下家的引用而接起来形成一条链。
    请求在这个链上传递，直到链上的某一个对象决定处理此请求。
    客户并不知道链上的哪一个对象最终处理这个请 求，系统可以在不影响客户端的情况下动态的重新组织链和分配责任。
    处理者有两个选择：承担责任或者把责任推给下家。一个请求可以最终 不被任何接收端对象所接受。

    如系统的异常处理、则一级一级向上传递、直到有相应程序进行处理
*****/

//抽象管理者
class Manager
{
protected:
    Manager *m_manager;
    string m_name;
public:
    Manager(Manager *manager, string name):m_manager(manager), m_name(name){}
    virtual void DealWithRequest(string name, int num)  {}
};
//经理
class CommonManager: public Manager
{
public:
    CommonManager(Manager *manager, string name):Manager(manager,name) {}
    void DealWithRequest(string name, int num)
    {
        if(num < 500) //经理职权之内
        {
            cout<<"manager "<<m_name<<"agree "<<name<<"salary "<<num<<" dollar"<<endl;
        }
        else
        {
            cout<<"manager "<<m_name<<"no primit,commit to chief"<<endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};
//总监
class Majordomo: public Manager
{
public:
    Majordomo(Manager *manager, string name):Manager(manager,name) {}
    void DealWithRequest(string name, int num)
    {
        if(num < 1000) //总监职权之内
        {
            cout<<"chief "<<m_name<<"agree "<<name<<"add "<<num<<" dollar"<<endl<<endl;
        }
        else
        {
            cout<<"chief"<<m_name<<"no primit,commit to chairMan"<<endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};
//总经理
class GeneralManager: public Manager
{
public:
    GeneralManager(Manager *manager, string name):Manager(manager,name) {}
    void DealWithRequest(string name, int num)  //总经理可以处理所有请求
    {
        cout<<"chairMan "<<m_name<<"agree "<<name<<"add "<<num<<" dollar"<<endl<<endl;
    }
};

#endif // DUTYLIST_H
