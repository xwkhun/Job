#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6+10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[l], i = l - 1, j = r + 1;
    while(i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if(i < j)
        {
            swap(q[i], q[j]);
        }
    }

    quick_sort(q, l, i-1);
    quick_sort(q, i, r);
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


void QuickSort(vector<int> &arr, int l, int r)
{
    // 判断左右指针是否相遇
    if (l >= r)
        return;

    int x = arr[l], i = l, j = r;
    while(i < j)
    {
        while(i < j && arr[j] >= x) j--;
        if (i < j) arr[i] = arr[j];  // 右指针停下，说明这个数应该放在左边，赋值给左指针所在的位置

        while(i < j && arr[i] <= x) i++;
        if (i < j) arr[j] = arr[i];  // 左指针停下，说明这个数应该放在右边，赋值给右指针所在的位置
    }
    arr[i] = x;
    QuickSort(arr, l, i);
    QuickSort(arr, i + 1, r);
}


int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i ++ )
    //     scanf("%d", &q[i]);

    // quick_sort(q, 0, n-1);

    // for (int i = 0; i < n; i++)
    //     printf("%d ", q[i]);

    vector<int> arr = {8, 4};
    int len = arr.size();

    QuickSort(arr, 0, len - 1);
    printArray(arr, len);

    return 0;
}

