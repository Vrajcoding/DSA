#include<iostream>
#include<vector>
using namespace std;
int search(int arr[], int si, int ei, int tar) {
    if(si > ei) {
        return -1;
    }
    
    int mid = si + (ei - si) / 2;

    if(arr[mid] == tar) {
        return mid;
    }
    if(arr[si] <= arr[mid]) { // L1
      if(arr[si] <= tar && tar <= arr[mid]) {
        // left side
        return search(arr, si, mid-1,tar);
      } else {
        // right side
        return search(arr,mid+1,ei,tar);
      }
    } else { // L2
            if(arr[mid] <= tar && tar <= arr[ei]) {
        // right side
         return search(arr,mid+1,ei,tar);
       
      } else {
        // left side
        return search(arr, si, mid-1,tar);
      }
    }

}

int main() {


    return 0;
}