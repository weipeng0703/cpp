/*
二维数组定义的四种方式：

1.数据类型 数组名[ 行数 ][ 列数 ];
2.数据类型 数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };
3.数据类型 数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};
4.数据类型 数组名[ ][ 列数 ] = { 数据1，数据2，数据3，数据4};

建议：以上4种定义方式，利用第二种更加直观，提高代码的可读性
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{

    // 1.数据类型 数组名[ 行数 ][ 列数 ];
    int arry[2][3];

    arry[0][0] = 1;
    arry[0][1] = 2;
    arry[0][2] = 3;
    arry[1][0] = 4;
    arry[1][1] = 5;
    arry[1][2] = 6;

    // cout << arry[0][0] <<endl; 

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arry[i][j] << endl;
        }
        
    }

    // 2.数据类型 数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };

    int arry1[2][3] = 
    {
        {1,2,3},
        {4,5,6}
    };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arry1[i][j] << " ";
        }

        cout << endl;
        
    }
    // 3.数据类型 数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};

    int arry2[2][3] = {1,2,3,4,5,6};   // 自己识别

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arry2[i][j] << " ";
        }

        cout << endl;
        
    }
    // 4.数据类型 数组名[ ][ 列数 ] = { 数据1，数据2，数据3，数据4};

    int arry3[][3] = {1,2,3,4,5,6};   //自己计算，不可省去列数

    // int arry3[2][] = {1,2,3,4,5,6};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arry3[i][j] << " ";
        }

        cout << endl;
        
    }
    return 0;
}

