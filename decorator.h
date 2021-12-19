#ifndef DECORATOR_H
#define DECORATOR_H
#include <string>
#include <iostream>
using namespace std;
//装饰模式
/*****
装饰模式：动态地给一个对象添加一些额外的职责。
就增加功能来说，装饰模式相比生成子类更为灵活。
有时我们希望给某个对象而不是整个类添加一些功能。
比如有一个手机，允许你为手机添加特性，比如增加挂件、屏幕贴膜等。
一种灵活的设计方式是，将手机嵌入到另一对象中，由这个对象完成特性的添加，我们称这个嵌入的对象为装饰。
这个装饰与它所装饰的组件接口一致，因此它对使用该组件的客户透明


*****/

//公共抽象类
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void ShowDecorate() {}
};

//具体的手机类
class iPhone : public Phone
{
private:
    string m_name; //手机名称
public:
    iPhone(string name): m_name(name){}
    ~iPhone() {}
    void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};
//具体的手机类
class NokiaPhone : public Phone
{
private:
    string m_name;
public:
    NokiaPhone(string name): m_name(name){}
    ~NokiaPhone() {}
    void ShowDecorate() { cout<<m_name<<"'s decorate "<<endl;}
};

//装饰类
class DecoratorPhone : public Phone
{
private:
    Phone *m_phone;  //要装饰的手机
public:
    DecoratorPhone(Phone *phone): m_phone(phone) {}
    virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};
//具体的装饰类
class DecoratorPhoneA : public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
    void AddDecorate() { cout<<"add Decorate1"<<endl; } //增加的装饰
};
//具体的装饰类
class DecoratorPhoneB : public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
    void AddDecorate() { cout<<"add Decorate2"<<endl; } //增加的装饰
};



#endif // DECORATOR_H
