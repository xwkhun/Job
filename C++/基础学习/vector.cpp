#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


void printArray(int val)
{
    cout << val << endl;
}


void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 第一种遍历方式
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    // 第二种遍历方式，这里it是个迭代器（也是指针），因此解引用可以拿到值
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++ )
    {
        cout << *it << endl;
    }

    // 第三种遍历方式
    for_each(v.begin(), v.end(), printArray);
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

// vector容器中存放自定义数据类型
void test02()
{
    // 创建自定义数据
    Person p1("小明", 12);
    Person p2("小佛", 20);
    Person p3("小红", 16);
    Person p4("小像", 4);
    Person p5("小均", 22);

    // 向容器中添加数据
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it ++ )
    {
        // cout << (*it).m_name << (*it).m_age << endl;
        cout << it->m_name << it->m_age << endl;
    }
}


// 容器嵌套容器
void test03()
{
    // 定义第一维容器
    vector<vector<int>> v;

    // 定义第二维容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;

    for (int i = 0; i < 5; i ++ )
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
        v5.push_back(i + 5);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);


    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it ++ )
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit ++ )
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}


int main()
{
    // test01();

    // test02();

    test03();

    system("pause");

    return 0;
}