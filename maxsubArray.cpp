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

int main() {
    int arr[] = {-5,-4,-10,-20};
    int n = sizeof(arr) / sizeof(int);
  MaxSubarray(arr,n);
    return 0;
}