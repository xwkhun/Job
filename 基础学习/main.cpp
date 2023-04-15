#include <iostream>
using namespace std;


void add(int *p)
{
    *p += 12;
    cout << &p << endl;
}

int main(){
    cout << "Hello, VSCode! " << endl;

    int a = 10;
    int *p = &a;
    cout << &p << endl;
    add(&a);
    cout << *p << endl;


    int x = 1;
    cout << "before: " << x << endl;

    const int* px = &x;
    // *px = 2; // 编译错误
    int* py = const_cast<int*>(px);
    *py = 2;

    cout << "px: " << px << endl;
    cout << "py: " << py << endl;
    cout << "after : " << x << endl;


    return 0;
}