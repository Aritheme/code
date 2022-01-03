/**************************************************
   > File Name:main.cpp
   > Author: arith
   > Created Time:2022年01月01日 星期六 19时08分57秒
**************************************************/
#include<iostream>
#include "../headers/copyswap.h"
using namespace std;
int main(int nArgc, char* argv[])
{
    SampleCopySwap obj1(5, 1,5), obj2(10, 3, 8);
    cout<<"print obj1 element\n";
    obj1.print();
    cout<<"obj1 element print done\n";
    cout<<"print obj2 element\n";
    obj2.print();
    cout<<"obj2 element print done\n";
    obj1=obj2;
    cout<<"print obj1 element\n";
    obj1.print();
    return 0;
}

