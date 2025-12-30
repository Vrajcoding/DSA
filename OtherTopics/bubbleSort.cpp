#include <iostream>
#include <climits>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            print(arr, n);
            return;
        }
    }

    print(arr, n);
}
int main()
{
    int arr[5] = {1,3,3,4,5};
    int n = 5;
    bubbleSort(arr, n);
    return 0;
}