#include<iostream>
#include<vector>
using namespace std;
int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];

    int i = si - 1;

    for(int j = si;j < ei;j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);

    return i;
}
int Decpartition(int arr[], int si, int ei) {
    int pivot = arr[ei];

    int i = si - 1;

    for(int j = si;j < ei;j++) {
        if(arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);

    return i;
}
void quickSort(int arr[], int si, int ei) {
     if(si >= ei) {
        return;
     }


    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, ei);
}

void printArr(int arr[],int n) {
    for(int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
}
int main() {
   int arr[] = {2,6,7,3,4,6};
   int n = 6;

   quickSort(arr, 0, n-1);
   printArr(arr, n);

    return 0;
}