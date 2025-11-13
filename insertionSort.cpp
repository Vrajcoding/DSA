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
void insertionSort(int *arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }

        arr[prev + 1] = curr;
    }
    print(arr, n);
}
int main()
{
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);
    return 0;
}