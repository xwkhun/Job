#include <iostream>
#include <vector>

using namespace std;
const int N = 100010;
int tmp[N];

template<typename T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i ++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void MergeSort(vector<int> &arr, int l, int r)
{
    // 递归终止条件
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    // int *tmp = new int[l + mid + r];

    // 递归排序两个区间
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);

    // 归并两个区间
    int k = 0, i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    // 把剩余数据拷贝到tmp中
    while(i <= mid)
        tmp[k++] = arr[i++];
    while(j <= r)
        tmp[k++] = arr[j++];
    

    // 把tmp数组中数据拷回原数组
    for (int i = l, j = 0; i <= r; i++, j++)
        arr[i] = tmp[j];
}

int main()
{
    vector<int> arr = {2, 5, 9, 4, 3, 2, 4};
    int len = arr.size();
    cout << (3 >> 1) << endl;

    MergeSort(arr, 0, len - 1);
    printArray(arr, len);
    return 0;
}