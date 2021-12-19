#ifndef FACTORYPATTERN_H
#define FACTORYPATTERN_H
#include <string>
#include <memory>
using namespace std;

/******
    需要抽象工厂：声明了工厂方法的接口。
    具体产品工厂：实现工厂方法的接口，负责创建产品对象。
    产品抽象类或接口：定义工厂方法所创建的产品对象的接口。
    具体产品实现：具有统一父类的具体类型的产品。
    每一种产品对应一个工厂子类，在创建具体对象时，实例化不同的工厂子类。但是，如果业务涉及的子类越来越多，难道每一个子类都要对应一个工厂类吗？
    这样会使得系统中类的个数成倍增加，增加了代码的复杂度。
    工厂方法模式也有缺点，每增加一种产品，就需要增加一个对象的工厂。
    在C++实现中，就是要定义一个个的工厂类。显然，相比简单工厂模式，工厂方法模式需要更多的类定义；

*******/

namespace FactoryPattern
{
enum CarType
{
    Bicycle_CAR = 1,
    Bus_CAR,
    Motor_CAR
};
class Car
{
public:
    Car(string name)
    {
        _nameStr = name;
    }
    virtual void open() = 0;
    string _nameStr;
};

class Bicycle : public Car
{
public:
    using Car::Car;

    void open()
    {
        printf("open %s Bicycle \n",_nameStr.data());
    }
};

class Bus : public Car
{
public:
    using Car::Car;
    void open()
    {
        printf("open %s Bus \n",_nameStr.data());
    }
};

class Motor  : public Car
{
public:
    using Car::Car;

    void open()
    {
        printf("open %s Motor \n",_nameStr.data());
    }
};

class Factory
{
public:
    virtual Car* createCar() = 0;
};

class BicycleFactory : public Factory
{
public:
    Car* createCar()
    {
        return new Bicycle("default");
    }
};

class BusFactory : public Factory
{
public:
    Car* createCar()
    {
        return new Bus("default");
    }
};

class MotorFactory : public Factory
{
public:
    Car* createCar()
    {
        return new Motor("default");
    }
};

}


#endif // FACTORYPATTERN_H
