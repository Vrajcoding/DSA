#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &arr,int i,int n){
    int l = i*2 + 1;
    int r = i*2 + 2;

    int maxI = i;
    if(l < n && arr[l] > arr[maxI]) {
        maxI = l;
    }

    if(r < n && arr[r] > arr[maxI]) {
        maxI = r;
    }

    if(maxI != i) {
        swap(arr[maxI], arr[i]);
        heapify(arr, maxI, n);
    }
}
void heapSort(vector<int> &arr) {
    int n = arr.size();
    // step 01: build max heap
    for(int i = n/2 - 1;i >= 0;i--) {
        heapify(arr, i, n);
    }

    //step 02:Now using heapify to sort the arr
    for(int i = (n-1);i > 0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
int main() {
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}
