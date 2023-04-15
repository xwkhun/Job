#include <iostream>
using namespace std;

/*

函数模板
其作用是 建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表
注意事项：
1、 自动类型推导，必须推导出一致的数据类型T才可以使用 （无法进行隐式类型转换，比如输入一个int，一个char，无法将char隐式转为int）
2、 模板必须要确定出 T 的数据类型才可以使用
3、 显示指定类型，能发生隐式类型转换


普通函数与函数模板调用规则
1、如果函数模板和普通函数都可以调用，优先调用普通函数
2、可以通过空模板参数列表 强制调用函数模板
3、函数模板也可以发生重载
4、如果函数模板可以产生更好的匹配，优先调用函数模板
既然提供了模板，就不要提供普通函数，容易产生二义性
*/


// 函数模板声明
// template 声明创建模板 
// typename 表明其后面的符号是一种数据类型，可以替换成class    
// T 通用的数据类型，名称可以替换，通常为大写字母
template<typename T>   
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


// 选择排序算法
template<typename T>
void select_sort(T arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        int min_idx = i;
        // 寻找i之后的最值
        for (int j = i + 1; j < arr_len; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                // 更新最小值下标
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            // 交换max_idx 和 i元素
            myswap(arr[i], arr[min_idx]);
        }
        
    }

}

// 打印数组模板
template<typename T>
void printArray(T arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}


class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    string m_name;
    int m_age;
};


template<typename T> 
bool myCompare(T &a, T &b)
{
    if(a.m_name == b.m_name && a.m_age == b.m_age)
        return true;
    else
        return false;
}


// 具体化模板优先调用
template<> bool myCompare(Person &a, Person &b)
{
    if(a.m_name == b.m_name && a.m_age == b.m_age)
        return true;
    else
        return false;
}


/*
类模板和函数模板类似，在模板声明后跟着类，就是模板类
区别：
1、类模板没有自动类型推导
2、类模板在模板参数列表中可以有默认参数

类模板中成员函数的调用时机：
类模板中的成员函数不是一开始就创建，而是在调用的时候才创建

通过类模板创建的对象，有三种方式像函数中进行传参：指定参数类型、参数模板化、类模板化
使用比较广泛的是第一种
*/
template<class NameType, class AgeType = int>
class Person2
{
public:
    Person2(NameType name, AgeType age)
    {
        m_name = name;
        m_age = age;
    }
    string m_name;
    int m_age;
};



int main()
{
    int a = 10;
    int b = 30;

    // 方法1：自动类型推断
    myswap(a, b);
    cout << "a = " << a << " b = " << b << endl;

    // 方法2：显示指定类型
    myswap<int>(a, b);
    cout << "a = " << a << " b = " << b << endl;


    // 测试数组 1 
    int arrInt[] = {5, 85, 10, 54, 63, 8};
    int num = sizeof(arrInt) / sizeof(int);

    select_sort(arrInt, num);
    printArray(arrInt, num);

    // 测试数组 2
    char arrChar[] = "badcfe";
    int num_char = sizeof(arrChar) / sizeof(char);  // 字符串数组最后以"\0"结尾，因此真实的长度要减去一
    cout << "num_char = " << num_char << endl;

    select_sort(arrChar, num_char);
    printArray(arrChar, num_char);

    Person p1("Tom", 10);
    Person p2("Tom", 10);

    cout << myCompare(p1, p2) << endl;

    system("pause");

    return 0;
}