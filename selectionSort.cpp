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
void selectionSort(int *arr, int n) {
    for(int i = 0;i < n-1;i++){
        int minIndex = i;
        for(int j= i+1;j < n;j++){
             if(arr[j] < arr[minIndex]) {
                minIndex = j;
             }
        }

        swap(arr[i],arr[minIndex]);
    }
    print(arr, n);
}
int main(){
   int arr[] = {5,3,4,2,1};
   int n = sizeof(arr) / sizeof(int);

   selectionSort(arr, n);

    return 0;
}