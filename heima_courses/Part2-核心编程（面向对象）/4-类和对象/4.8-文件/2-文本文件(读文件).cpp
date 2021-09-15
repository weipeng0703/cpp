/*
读文件与写文件步骤相似，但是读取方式相对于比较多

读文件步骤如下：
    1.包含头文件
    #include <fstream>

    2.创建流对象
    ifstream ifs;

    3.打开文件并判断文件是否打开成功
    ifs.open(“文件路径”,打开方式);

    4.读数据
    四种方式读取

    5.关闭文件
    ifs.close();
*/
#include<iostream>
#include<string>
// 1.包含头文件
#include<fstream> 
using namespace std;

void test1()
{
    // 2.创建输入流对象
    ifstream ifs;

    // 3.打开文件并判断是否打开成功
    ifs.open("test.txt",ios::in);

    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }
    

    // 4.读数据
    // (1)
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    // (2)
    // char buf[1024] = {0};
    // while (ifs.getline(buf,sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // (3)
    string buf;
    while (getline(ifs,buf))
    {
        cout << buf << endl;
    }

    // (4)不太推荐
    // char c;
    // while ((c = ifs.get()) != EOF)   // EOF——End Of File
    // {
    //     cout << c << endl;
    // }



    // 5.关闭文件
    ifs.close();
}

int main()
{
    test1();

    return 0;
}