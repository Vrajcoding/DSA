#include <iostream>
#include <climits>
using namespace std;
int linearSerach(int *arr,int n,int target) {
   for(int i = 0;i < n;i++) {
    if(target == arr[i]) {
        return i;
    }
   }
  return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,10,3};
    int n = sizeof(arr) / sizeof(int);
    cout << "Value exist index :" << linearSerach(arr,n,10) << endl;
    return 0;
}