#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid+1;


    while(i <= mid && j <= ei) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    for(int i = si, x = 0;i <= ei;i++) {
            arr[i] = temp[x++];
    }

}

void Desmerge(int arr[],int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid+1;


    while(i <= mid && j <= ei) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[j++]);
            } else {
                temp.push_back(arr[i++]);
            }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    for(int i = si, x = 0;i <= ei;i++) {
            arr[i] = temp[x++];
    }

}
void mergesort(int arr[],int si,int ei) {
    if(si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;
    mergesort(arr, si, mid); // left side
    mergesort(arr, mid+1, ei); // right side

    merge(arr, si, mid, ei);
}


void printArr(int arr[],int n) {
    for(int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
}
int main() {
   int arr[] = {2,5,7,3,4,6};
   int n = 6;

   mergesort(arr, 0, n-1);
   printArr(arr, n);

    return 0;
}