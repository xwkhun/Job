#include <iostream>

using namespace std;

// 函数对象
/*
函数对象本质上是个类，重载函数调用操作符的类，其对象称为函数对象
函数对象使用重载的（）时，行为类似函数调用，也叫仿函数

特点：
函数对象在使用时，可以像普通函数那样调用，可以有参数，也可以有返回值
函数对象超出普通函数的概念，可以有自己的状态
函数对象可以作为参数传递
*/

class Myadd
{
public:
    int operator()(int val1, int val2)
    {
        return val1 + val2;
    }

};


void test01()
{
    Myadd p;
    cout << p(10, 12) << endl;
}

int main()
{
    test01();

    return 0;
}