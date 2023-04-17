#include <iostream>
#include <list>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
    {
        m_Name = name;
        m_Age = age;
        m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

bool person_sort_rule(const Person &p1, const Person &p2)
{
    if(p1.m_Age == p2.m_Age)
        return p1.m_Height > p2.m_Height;
    else
        return p1.m_Age < p2.m_Age;
}

void pringList(list<Person> &l)
{
    for (list<Person>::iterator it = l.begin(); it != l.end(); it ++ )
    {
        cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
    }
}

void test01()
{
    // 创建数据
    Person p1("小明", 20, 186);
    Person p2("小辉", 18, 162);
    Person p3("小岚", 18, 172);

    // 存储数据
    list<Person> L;
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);

    cout << "排序前： " << endl;
    pringList(L);

    // 排序
    L.sort(person_sort_rule);
    cout << "排序后： " << endl;
    pringList(L);
}

int main()
{
    test01();
    return 0;
}