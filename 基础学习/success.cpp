#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;  //私有成员只是被隐藏了，还是继承下去了
};

class Son: public Base
{
public:
    int m_D;
};


void test_01()
{
    cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{
    // 父类中所有非静态成员属性都会被子类中继承下去，只是父类的私有成员变量是被编译器隐藏了，因此访问不了
    test_01();
    return 0;
}

// 如何利用开发人员命令提示符查看对象模型
// 跳转盘符
// 跳转到文件路径 cd 具体路径下
// 查看命名 dir
// cl /dl reportSingleClassLayout类名 文件名
