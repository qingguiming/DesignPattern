#ifndef BRIDGEPATTERN_H
#define BRIDGEPATTERN_H
#include <iostream>
using namespace std;

//桥接模式

/****

桥接模式：将抽象部分与实现部分分离，使它们都可以独立变换。

    以下情形考虑使用桥接模式：

    当一个对象有多个变化因素的时候，考虑依赖于抽象的实现，而不是具体的实现。

    当多个变化因素在多个对象间共享时，考虑将这部分变化的部分抽象出来再聚合/合成进来。

    当一个对象的多个变化因素可以动态变化的时候。

    优点：

    将实现抽离出来，再实现抽象，使得对象的具体实现依赖于抽象，满足了依赖倒转原则。

    更好的可扩展性。

    可动态的切换实现。桥接模式实现了抽象和实现的分离，在实现桥接模式时，就可以实现动态的选择具体的实现。
******/


//操作系统
class OS
{
public:
    virtual void InstallOS_Imp() {}
};
class WindowOS: public OS
{
public:
    void InstallOS_Imp() { cout<<"install Windows OS"<<endl; }
};
class LinuxOS: public OS
{
public:
    void InstallOS_Imp() { cout<<"install Linux OS"<<endl; }
};
class UnixOS: public OS
{
public:
    void InstallOS_Imp() { cout<<"install Unix OS"<<endl; }
};
//计算机
class Computer
{
public:
    virtual void InstallOS(OS *os) {}
};
class DellComputer: public Computer
{
public:
    void InstallOS(OS *os)
    {
        os->InstallOS_Imp();
        cout<<"run in Dell"<<endl;
    }
};
class AppleComputer: public Computer
{
public:
    void InstallOS(OS *os)
    {
        os->InstallOS_Imp();
        cout<<"run in Apple"<<endl;

    }
};
class HPComputer: public Computer
{
public:
    void InstallOS(OS *os)
    {
        os->InstallOS_Imp();
        cout<<"run in HP"<<endl;

    }
};


#endif // BRIDGEPATTERN_H
