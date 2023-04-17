#include <iostream>
#include <vector>
using namespace std;

// // 定义交换模板函数
// template<typename T>
// void swap(T &a, T &b)
// {
//     T temp;
//     temp = a;
//     a = b;
//     b = temp;
// }


 // 暴力法
void bubble_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i ++ )
    {
        for (int j = 0; j < len - 1; j ++ )
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// 优化版
void BubbleSort(vector<int> &arr, int n)
{
    // 特判
    if(n <= 1) return;
    // 设置标志
    bool is_swap;

    for (int i = 1; i < n; ++ i)
    {
        is_swap = false;
        for (int j = 1; j < n - i + 1; ++ j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j - 1], arr[j]);
                is_swap = true;
            }
        }

        // 本轮没有发生交换，说明已经排序完成，提前退出循环
        if(!is_swap)
            break; 
    }
}

template<typename T>
void printArray(T &arr, int len)
{
    for (auto i = 0; i < len; i ++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr1[] = {4, 5, 6, 3, 2, 1};
    int len = sizeof(arr1) / sizeof(int);
    bubble_sort(arr1, len);
    printArray(arr1, len);

    vector<int> arr2 = {4, 5, 6, 3, 2, 1};
    len = arr2.size();
    BubbleSort(arr2, len);
    printArray(arr2, len);
}