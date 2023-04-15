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

void SelectSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    int min_idx;
    for (int i = 0; i < n; ++i)
    {
        min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 1, 3, 2};
    int len = arr.size();

    SelectSort(arr, len);
    printArray(arr, len);

    return 0;
}