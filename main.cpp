#include <iostream>
#include "simplefactory.h"
#include "factorypattern.h"
#include "abstractfactory.h"
#include "singleton.h"
#include "builderpattern.h"
#include "propertypattern.h"
#include "adapter.h"
#include "decorator.h"
#include "facadepattern.h"
#include "bridgepattern.h"
#include "strategypattern.h"
#include "observer.h"
#include "dutylist.h"
#include "mementopattern.h"
#include "meditorpattern.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    //简单工厂
#ifdef SIMPLE_FACTORY

    Car *newCar= nullptr;
    SimpleFactory factory;
    newCar = factory.createCar(Bus_CAR);

    if(newCar)
    {
        newCar->open();
    }

#endif

#ifdef SIMPLE_FACTORY

    std::shared_ptr<Car> newCar;
    SimpleFactory factory;
    newCar = factory.createCarByNewWay(Bus_CAR);

    if(newCar.use_count() > 0)
    {
        newCar->open();
    }

#endif
    //工厂模式
#ifdef FACTORY_PARTERN
    FactoryPattern::Car *newCar= nullptr;
    FactoryPattern::BusFactory bFactory;

    newCar = bFactory.createCar();

    if(newCar)
    {
        newCar->open();
    }

#endif
    //抽象工厂
#ifdef ABSTRACT_FACTORY

    AbstractFactory::AudiFactory aFactory;
    AbstractFactory::Car *pCar = nullptr;
    AbstractFactory::Engine *pEngine = nullptr;

    pCar = aFactory.createCar(AbstractFactory::Bus_CAR);
    pEngine = aFactory.createEngine(AbstractFactory::Plane_Engine);

    if(pCar)
    {
        pCar->open();
    }

    if(pEngine)
    {
        pEngine->showLogo();
    }
#endif
    //单例
#ifdef SINGLETON
    SingletonA::getInstance();
    SingletonB::getInstance();
    SingletonB::getInstance();
    SingletonB::getInstance();

#endif

    //建造者模式
#ifdef BUILDER
    ThinBuilder* pTBuilder = new ThinBuilder();
    Director dir(pTBuilder);
    dir.Create();

#endif

    //原型模式
#ifdef PROPERTY
    Resume *r1 = new ResumeA("A");
    Resume *r3 = r1->Clone();
    r1->Show();
    r3->Show();

#endif

    //适配器模式
#ifdef ADAPTER

    UdpApdpter adapter;
    adapter.writeDataToServer(string("hello"));
#endif

    //装饰模式
#ifdef DECORATOR
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone); //装饰，增加挂件
    Phone *dpb = new DecoratorPhoneB(dpa);    //装饰，屏幕贴膜
    dpa->ShowDecorate();
    dpb->ShowDecorate();

#endif

    //外观模式
#ifdef FACADE
    computer c;
    c.start();
    c.shutDown();
#endif

    //桥接模式
#ifdef BRIDGE

    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();
    Computer *computer1 = new AppleComputer();
    computer1->InstallOS(os1);
    computer1->InstallOS(os2);


#endif

    //策略模式

#ifdef STRATEGY


    Cache cache(LRU); //指定标签即可
    cache.Replace();

#endif
    //观察模式
#ifdef OBSERVER
    Blog *blog = new BlogCSDN("qgm blog ");
    Observer *observer1 = new ObserverBlog("tutupig", blog);
    blog->Attach(observer1);
    blog->SetStatus("publish a blog about design pattern");
    blog->Notify();

#endif
    //职责链模式
#ifdef DUTYLIST
    Manager *general = new GeneralManager(NULL, "A"); //设置上级，总经理没有上级
    Manager *majordomo = new Majordomo(general, "B"); //设置上级
    Manager *common = new CommonManager(majordomo, "C"); //设置上级
    common->DealWithRequest("D",300);   //员工D要求加薪
    common->DealWithRequest("E", 600);
    common->DealWithRequest("F", 1000);

#endif

    //备忘录模式
#ifdef MEMENTO
    Caretake caretake;
    GameRole role;
    role.Show();   //初始值
    caretake.Save(role.Save()); //保存状态
    role.Attack();
    role.Show();  //进攻后
    role.Load(caretake.Load(0)); //载入状态
    role.Show();  //恢复到状态0


#endif
    //中介者模式

#ifndef Meditor

    HouseMediator* hMediator = new HouseMediator;
    Buyer* buyer = new Buyer(hMediator);
    Seller* seller = new Seller(hMediator);

    hMediator->setBuyer(buyer);
    hMediator->setSeller(seller);
    buyer->sendMessage("Sell not to sell?");
    seller->sendMessage("Of course selling!");


#endif

    return 0;
}
