#include <iostream>

using namespace std;

// 判断是否是质数
bool isPrime(unsigned n)
{
    for (int i = 2; i < n; i ++ )
    {
        if (n % i == 0)
            return true;
    }
    return false;
}

// 判断是否是丑数
bool isUgly(unsigned n)
{
    if (n > 1)
    {
        while(n % 2 == 0)
            n /= 2;
        while(n % 3 == 0)
            n /= 3;
        while(n % 5 == 0)
            n /= 5;
        
        if (n == 1)
            return true;
        else
            return false;
    }
    else if (n == 1)
        return true;
}

// 斐波那契数列
int fabonacciSequence(unsigned n)
{
    long result[] = {0, 1};
    if (n < 2)
        return result[n];

    long first = 0;
    long second = 1;
    long sum;

    for (int i = 2; i < n; i ++ )
    {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}