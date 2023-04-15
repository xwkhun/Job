#include <iostream>
#include <string>
using namespace std;

class Person
{

public:
    // 默认构造函数：空实现
    Person(){};

    // 构造函数重载
    Person(int money)
    {
        m_money = new int(money);  // 开辟一个堆区数据，new返回的是地址，因此要用指针来接收
    }

    // 重新实现拷贝构造函数
    Person(const Person &p)
    {
        m_age = p.m_age;
        m_phone = p.m_phone;

        // 重新开辟一块堆区空间存放拷贝后的数据，即深拷贝，即可解决重复同一块内存空间的问题
        m_money = new int(*p.m_money);
    }

    ~Person()
    {
        if(m_money != NULL)
        {
            delete m_money;
            m_money = NULL;
        }
    }

public:
    // 成员函数重载运算符 + 
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_age = this->m_age + p.m_age;
    //     return temp;
    // }

    // 成员函数重载运算符 <<   无法实现

    // 成员函数重载运算符 前置++
    // 这里返回类型使用引用，返回引用是为了可以一直对一个数据进行递增操作  
    Person& operator++()
    {
        // 属性自增运算
        m_age++;
        // 自增操作完，将类自身作为返回
        return *this;
    }

    // 成员函数重载运算符 后置++
    // 为了与前置++区分进行重载，添加一个占位符作为参数，即区分前置和后置递增
    // 这里的返回类型不使用引用，因为temp是个局部变量，在当前函数执行完后就会被释放，如果对temp进行引用会产生非法操作
    Person operator++(int)
    {
        // 先记录当时的属性值
        Person temp = *this;

        // 再递增
        m_age++;

        // 最后将记录结果做返回
        return temp;
    }

    // 成员函数重载运算符=
    // 利用深拷贝解决浅拷贝带来的问题
    Person& operator=(Person &p)
    {
        // 先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_money != NULL)
        {
            delete m_money;
            m_money = NULL;
        }

        m_money = new int(*p.m_money);
        // 返回自身
        return *this;  
    }

    // 成员函数重载运算符==
    bool operator==(Person &p)
    {
        if(m_age == p.m_age && m_phone == p.m_phone && m_money == p.m_money)
            return true;
        else
            return false;
    }

    // 成员函数重载运算符!=
    bool operator!=(Person &p)
    {
        if(m_age == p.m_age && m_phone == p.m_phone && m_money == p.m_money)
            return false;
        else
            return true;
    }

    int *m_money;
    int m_age;
    string m_phone;


private:
    
};

// 全局函数重载运算符+  类相加
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_age = p1.m_age + p2.m_age;

    int *temp_money = new int(*p1.m_money + *p2.m_money);
    temp.m_money = temp_money;
    return temp;
}


// 全局函数重载运算符+  类与实数相加
Person operator+(Person &p1, int &num)
{
    Person temp;
    temp.m_age = p1.m_age + num;

    int *temp_money = new int(*p1.m_money + num);
    temp.m_money = temp_money;
    return temp;
}


// 全局函数重载运算符 <<
// 需要特别注意，当这里的p不采用引用的形式，那么这个函数执行完后p由于是拷贝了一份，程序会自动销毁拷贝的这份对象，析构函数若是释放堆区数据，后面会造成重复释放的问题
// 因此若是不使用引用的形式，那么就要在类中重新实现拷贝构造函数，重新分配堆区数据的地址，解决值传递时浅拷贝带来的问题
ostream& operator<<(ostream &cout, Person p)
{
    cout << p.m_age << " " << p.m_phone << " " << *p.m_money;
    return cout;
}


int main()
{
    Person p1(50);
    p1.m_age = 10;
    p1.m_phone = "13211111111";
    cout << "p1.m_age = " << p1.m_age << endl;
    cout << "p1.m_money = " << *p1.m_money << endl;

    Person p2(30);
    p2.m_age = 50;
    p2.m_phone = "18622222222";
    cout << "p2.m_age = " << p2.m_age << endl;
    cout << "p2.m_money = " << *p2.m_money << endl;

    int num = 20;

    // 实现操作1：两个类相加
    Person p3 = p1 + p2;
    // 实现操作2：一个类加一个实数
    Person p4 = p1 + num;

    cout << "p3.m_age = " << p3.m_age << endl;
    cout << "p3.m_money = " << *p3.m_money << endl;
    cout << "p4.m_age = " << p4.m_age << endl;
    cout << "p4.m_money = " << *p4.m_money << endl;

    // 实现操作3：直接输出对象 （成员变量的信息）
    cout << "这是p1: " << p1 << " " << "这是p2: " << p2 << endl;
    cout << "这是p3: " << p3 << " " << "这是p4: " << p4 << endl;

    // 实现操作4：类的前置自增 ++类
    cout << "++(++p1): " << ++(++p1) << endl;
    cout << "p1.m_age = " << p1.m_age << endl;

    // 实现操作5: 类的后置自增 类++
    cout << "p2++: " << p2++ << endl;
    cout << "p2.m_age = " << p2.m_age << endl;

    // 实现操作6：类的赋值操作 类1 = 类2
    p1 = p2;
    cout << "这是赋值后的p1: " << p1 << endl;

    // 实现操作7：类相等与不等判断
    if (p1 == p2)
        cout << "p1和p2是相等的。" << endl;
    else
        cout << "p1和p2是不相等的。" << endl;
    
    if (p1 != p2)
        cout << "p1和p2是不相等的。" << endl;
    else
        cout << "p1和p2是相等的。" << endl;

    system("pause");
    return 0;
}