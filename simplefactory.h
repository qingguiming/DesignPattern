#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H
#include <string>
#include <memory>
using namespace std;
/**
简单工厂模式（静态工厂模式）：
主要特点是需要在工厂类中做判断，从而创造相应的产品，当增加新产品时，需要修改工厂类。
使用简单工厂模式，我们只需要知道具体的产品型号就可以创建一个产品、可以容易扩展产品。
缺点：工厂类集中了所有产品类的创建逻辑，如果产品种类较多，会使得工厂类变的非常臃肿。
唯一工厂类，一个产品抽象类，工厂类的创建方法依据入参判断并创建具体产品对象。
*/


enum CarType
{
    Bicycle_CAR = 1,
    Bus_CAR,
    Motor_CAR
};
class Car
{
public:
    virtual void open() = 0;
private:
    string _nameStr;
};

class Bicycle : public Car
{
public:
    void open()
    {
        printf("open Bicycle \n");
    }
};

class Bus : public Car
{
public:
    void open()
    {
        printf("open Bus\n");
    }
};

class Motor  : public Car
{
public:
    void open()
    {
        printf("open Motor\n");
    }
};


class SimpleFactory
{
public:
    Car* createCar(CarType type)
    {
        Car* pRet =nullptr;
        switch (type) {
        case Bicycle_CAR:
            pRet = new Bicycle;
            break;
        case Bus_CAR:
            pRet = new Bus;
            break;
        case Motor_CAR:
            pRet = new Motor;
            break;
        default:
            break;
        }

        return pRet;
    }

    std::shared_ptr<Car> createCarByNewWay(CarType type)
    {
        std::shared_ptr<Car> ret;
        switch (type) {
        case Bicycle_CAR:
            ret = std::make_shared<Bicycle>();
            break;
        case Bus_CAR:
            ret = std::make_shared<Bus>();

            break;
        case Motor_CAR:
            ret = std::make_shared<Motor>();
            break;
        default:
            break;
        }

        return ret;
    }
};

#endif // SIMPLEFACTORY_H
