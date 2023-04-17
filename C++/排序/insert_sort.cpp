#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(T &arr, int len)
{
    for (auto i = 0; i < len; i ++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 方法1
void insert_sort(int arr[], int n)
{
    // 特判
    if (n <= 1) return;

    for (int i = 1; i < n; ++i)
    {
        int temp = arr[i];  // 将当前值存储下来，以免被替换没了
        int j;
        for (j = i - 1; j >= 0; --j)
        {
            // i之前的数依次和i比较，比i大就往后移动一位，直到找到小于或等于i的位置
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = temp;
    }
}

// 方法2
void InsertSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
            swap(arr[j - 1], arr[j]);
    }
}

int main()
{
    int arr1[] = {4, 5, 6, 3, 2, 1};
    int len = sizeof(arr1) / sizeof(int);
    insert_sort(arr1, len);
    printArray(arr1, len);

    vector<int> arr2 = {4, 5, 6, 3, 2, 1};
    len = arr2.size();
    InsertSort(arr2, len);
    printArray(arr2, len);
}