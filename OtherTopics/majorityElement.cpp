#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
void majorityElement1(int *arr,int n) {
  int index = 0,checkedIndex = 0;

  for(int i = 0;i < n-1;i++) {
    int check = 0;
    for(int j = i+1;j < n;j++) {
        if(arr[i] == arr[j]) {
            check++;
        }
    }

    if(check > checkedIndex) {
        checkedIndex = check;
       index = arr[i];
    }
  }
  cout << "majotiy element is :" << index << endl;
}

void majorityElement2(int *arr, int n) {
    sort(arr, arr+n);
    int mid = (n-1)/2;
    cout << "majotiy element is :" << arr[mid] << endl;
}

void majorityElement3(int *arr,int n) {
    int count = 0;
    int current;
    for(int i = 0;i < n;i++) {
        if(count == 0) {
            current = arr[i];
        } 
         if(current == arr[i]) {
              count++;
        } else {
            count--;
        }
    }

    cout << "majotiy element is :" << current << endl;
}
int main() {
  int arr[] = {2,2,3,1,3,1,1,1};
  int n = sizeof(arr) / sizeof(int);

  majorityElement1(arr, n);
  majorityElement2(arr, n);
  majorityElement3(arr, n);

    return 0;
}