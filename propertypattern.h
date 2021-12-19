#ifndef PROPERTYPATTERN_H
#define PROPERTYPATTERN_H
#include <iostream>
#include <string.h>
using namespace std;
//原型模式
/*****

    原型模式：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。通俗的讲就是当需要创建一个新的实例化对象时，
    我们刚好有一个实例化对象，但是已经存在的实例化对象又不能直接使用。这种情况下拷贝一个现有的实例化对象来用，可能会更方便。

    以下情形可以考虑使用原型模式：

    当new一个对象，非常繁琐复杂时，可以使用原型模式来进行复制一个对象。比如创建对象时，构造函数的参数很多，而自己又不完全的知道每个参数的意义，就可以使用原型模式来创建一个新的对象，不必去理会创建的过程。

    当需要new一个新的对象，这个对象和现有的对象区别不大，我们就可以直接复制一个已有的对象，然后稍加修改。

    当需要一个对象副本时，比如需要提供对象的数据，同时又需要避免外部对数据对象进行修改，那就拷贝一个对象副本供外部使用。
*****/
//父类
class Resume
{
protected:
    char *name;
public:
    Resume() {}
    virtual ~Resume() {}
    virtual Resume* Clone() { return nullptr; }
    virtual void Set(char *n) {}
    virtual void Show() {}
};

class ResumeA : public Resume
{
public:
    ResumeA(const char *str);  //构造函数
    ResumeA(const ResumeA &r); //拷贝构造函数
    ~ResumeA();                //析构函数
    ResumeA* Clone();          //克隆，关键所在
    void Show();               //显示内容
};
ResumeA::ResumeA(const char *str)
{
    if(str == nullptr)
    {
        name = new char[1];
        name[0] = '\0';
    }
    else
    {
        name = new char[strlen(str)+1];
        strcpy(name, str);
    }
}
ResumeA::~ResumeA() { delete [] name;}
ResumeA::ResumeA(const ResumeA &r)
{
    name = new char[strlen(r.name)+1];
    strcpy(name, r.name);
}
ResumeA* ResumeA::Clone()
{
    return new ResumeA(*this);
}
void ResumeA::Show()
{
    cout<<"ResumeA name : "<<name<<endl;
}


#endif // PROPERTYPATTERN_H
