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

void countingSort(int *arr,int n) {
  int freqarr[10000];
  int maxVal = INT_MIN, minVal = INT_MAX;
  for(int i = 0;i < n;i++) {
    maxVal = max(maxVal, arr[i]);
    minVal = min(minVal, arr[i]);
  }

  for(int i = 0;i < n;i++) {
    freqarr[arr[i]]++;
  }

  print(freqarr, n);
  for(int i = minVal,j = 0;i <= maxVal;i++) {
      while(freqarr[i] > 0) {
        arr[j++] = i;
        freqarr[i]--;
      }
  }

  print(arr, n);
}

int main() {
    int arr[] = {1,1,2,0,1,2,1};
    int n = sizeof(arr) / sizeof(int);
    countingSort(arr, n);
    return 0;
}