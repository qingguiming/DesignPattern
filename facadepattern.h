#ifndef FACADEPATTERN_H
#define FACADEPATTERN_H

/*****

外观模式
    门面模式：外部与一个子系统的通信必须通过一个统一的门面对象进行。
    门面模式提供一个高层次的接口，使得子系统更易于使用 。
    每一个子系统只有一个门面类，而且此门面类只有一个实例，也就是说它是一个单例模式。但整个系统可以有多个门面类
*****/

class Control
{
public:
    virtual void start() = 0;
    virtual void shutdown() = 0;
};
//主机
class Host : public Control
{
public:
    void start() override
    {
        printf("host start \n");
    }
    void shutdown() override
    {
        printf("host shutdown \n");

    }
};
//显示屏
class LCDDisplay  : public Control
{
public:
    void start() override
    {
        printf("LCDDisplay start \n");
    }
    void shutdown() override
    {
        printf("LCDDisplay shutdown \n");

    }
};
//外围设备

class Peripheral   : public Control
{
public:
    void start() override
    {
        printf("Peripheral start \n");
    }
    void shutdown() override
    {
        printf("Peripheral shutdown \n");

    }
};

class computer
{
public:
    void start()
    {
        _lcdDisplay.start();
        _peripheral.start();
        _host.start();
    }
    void shutDown()
    {
        _lcdDisplay.shutdown();
        _peripheral.shutdown();
        _host.shutdown();
    }
private:
    LCDDisplay _lcdDisplay;
    Peripheral _peripheral;
    Host _host;


};

#endif // FACADEPATTERN_H
