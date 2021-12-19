#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include <string>
#include <memory>
using namespace std;

/******
抽象工厂适用于以下情况：

抽象工厂：声明了创建抽象产品对象的操作接口。
具体产品工厂：实现了抽象工厂的接口，负责创建产品对象。
产品抽象类或接口：定义一类产品对象的接口。
具体产品实现：定义一个将被相应具体工厂创建的产品对象。


多个工厂类，多个产品抽象类，产品子类分组，同一个工厂实现类创建同组中的不同产品，减少了工厂子类的数量。
抽象工厂模式提供创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
当存在多个产品系列，而客户端只使用一个系列的产品时，可以考虑使用抽象工厂模式。
缺点：当增加一个新系列的产品时，不仅需要现实具体的产品类，还需要增加一个新的创建接口，扩展相对困难
****/

namespace AbstractFactory
{
enum CarType
{
    Bicycle_CAR = 1,
    Bus_CAR,
    Motor_CAR
};

enum EngineType
{
    Car_Engine = 1,
    Plane_Engine,
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

class Engine
{

public:
    Engine(string name = string("default")):_nameStr(name)
    {

    }
    virtual void showLogo() = 0;

protected:
    string _nameStr;
};

class CarEngine : public Engine
{
public:
    using Engine::Engine;
    void showLogo() override
    {
        printf("CarEngine %s \n",_nameStr.data());
    }
};

class PlaneEngine : public Engine
{
public:
    using Engine::Engine;
    void showLogo() override
    {
        printf("PlaneEngine %s \n",_nameStr.data());
    }
};

class Factory
{
public:
    virtual Car* createCar(CarType type) = 0;
    virtual Engine* createEngine(EngineType type) = 0;

};

class AudiFactory : public Factory
{
public:

    Car* createCar(CarType type)
    {
        Car* pRet =nullptr;
        switch (type) {
        case Bicycle_CAR:
            pRet = new Bicycle(_factoryName);
            break;
        case Bus_CAR:
            pRet = new Bus(_factoryName);
            break;
        case Motor_CAR:
            pRet = new Motor(_factoryName);
            break;
        default:
            break;
        }

        return pRet;
    }

    Engine* createEngine(EngineType type)
    {
        Engine* pRet =nullptr;
        switch (type) {
        case Car_Engine:
            pRet = new CarEngine(_factoryName);
            break;
        case Plane_Engine:
            pRet = new PlaneEngine(_factoryName);
            break;
        default:
            break;
        }

        return pRet;
    }


private:
    string _factoryName = "Audi";

};

class BenzFactory : public Factory
{
public:

    Car* createCar(CarType type)
    {
        Car* pRet =nullptr;
        switch (type) {
        case Bicycle_CAR:
            pRet = new Bicycle(_factoryName);
            break;
        case Bus_CAR:
            pRet = new Bus(_factoryName);
            break;
        case Motor_CAR:
            pRet = new Motor(_factoryName);
            break;
        default:
            break;
        }

        return pRet;
    }

    Engine* createEngine(EngineType type)
    {
        Engine* pRet =nullptr;
        switch (type) {
        case Car_Engine:
            pRet = new CarEngine(_factoryName);
            break;
        case Plane_Engine:
            pRet = new PlaneEngine(_factoryName);
            break;
        default:
            break;
        }

        return pRet;
    }


private:
    string _factoryName = "Benz";

};
}
#endif // ABSTRACTFACTORY_H
