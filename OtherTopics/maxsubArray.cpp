// kadane`s algoritham to solve subarray
#include<iostream>
#include<climits>
using namespace std;

void MaxSubarray(int *arr,int n) {
    int maxsum = 0,currentsum = 0;
    for(int i = 0;i < n;i++) {
        currentsum += arr[i];
        if(currentsum < 0) {
            currentsum = 0;
        }
        maxsum = max(maxsum, currentsum);
    }
    cout << "Maximum sum is :" << maxsum << endl;
}


//Leetcode 152 
// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element.

void MaxProductArray(int *arr,int n) {
    int maxProduct = INT_MIN,currentProduct = 1;
    for(int i = 0;i < n;i++) {
        currentProduct *= arr[i];
        cout << currentProduct << " ";
        if(currentProduct <= 0) {
            currentProduct = 1;
        }
        maxProduct = max(maxProduct, currentProduct);
    }

     cout << "Maximum Product is :" << maxProduct << endl;
}
int main() {
    int arr[] = {-2,0,-1};
    int n = sizeof(arr) / sizeof(int);
//   MaxSubarray(arr,n);
  MaxProductArray(arr,n);
    return 0;
}