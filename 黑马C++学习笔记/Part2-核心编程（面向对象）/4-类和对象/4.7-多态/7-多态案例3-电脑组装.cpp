/*
案例描述：

电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
测试时组装三台不同的电脑进行工作
*/
#include<iostream>
#include<string>
using namespace std;

// 抽象不同的零件类
// CPU
class CPU
{
public:
    // 计算函数
    virtual void calculate() = 0;


};

// 显卡
class VideoCard
{
public:
    // 显示函数
    virtual void Display() = 0;


};

// 内存条
class Memory
{
public:
    // 存储函数
    virtual void Store() = 0;


};

// 电脑类
class Computer
{
public:
    Computer(CPU * cpu, VideoCard * vc, Memory * mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;

    }

    // 工作函数
    void Work()
    {
        // 调用零件接口,让零件工作
        m_cpu->calculate();
        m_vc->Display();
        m_mem->Store();
    }

    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }

        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }

    }


private:
    CPU *m_cpu;       // CPU零件指针
    VideoCard *m_vc;  // 显卡零件指针
    Memory * m_mem;   // 内存条零件指针
};

// 具体厂商
// Intel;
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel生产的CPU开始计算" << endl;
    }

};

// 显卡
class IntelVideocard : public VideoCard
{
public:
    virtual void Display()
    {
        cout << "IntelVideocard生产的显卡开始显示" << endl;
    }

};


// 内存条
class IntelMemory : public Memory
{
public:
    virtual void Store()
    {
        cout << "IntelMemory生产的内存条开始存储" << endl;
    }

};


// Lenovo
class LenovoCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenovo生产的CPU开始计算" << endl;
    }

};

// 显卡
class LenovoVideocard : public VideoCard
{
public:
    virtual void Display()
    {
        cout << "LenovoVideocard生产的显卡开始显示" << endl;
    }

};


// 内存条
class LenovoMemory : public Memory
{
public:
    virtual void Store()
    {
        cout << "LenovoMemory生产的内存条开始存储" << endl;
    }

};



void test1()
{
    // 第一台电脑的零件
    CPU * intelCPU = new IntelCPU;
    VideoCard * intelVideocard = new IntelVideocard;
    Memory * intelMemory = new IntelMemory;

    // 第一台电脑
    cout << "第一台电脑开始工作" << endl;
    Computer * computer1 = new Computer(intelCPU, intelVideocard, intelMemory);
    computer1->Work();
    delete computer1;
    cout << "------------------" << endl;


     // 第二台电脑
    cout << "第二台电脑开始工作" << endl;
    Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideocard, new LenovoMemory);
    computer2->Work();
    delete computer2;
    cout << "------------------" << endl;

    // 第三台电脑
    cout << "第三台电脑开始工作" << endl;
    Computer * computer3 = new Computer(new IntelCPU, new LenovoVideocard, new LenovoMemory);
    computer3->Work();
    delete computer3;
    cout << "------------------" << endl;

}

int main()
{
    test1();

    return 0;
}