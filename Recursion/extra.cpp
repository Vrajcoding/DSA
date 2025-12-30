#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> arr,int target,int i) {
    if(i == arr.size()) {
        return -1;
    }


    if(arr[i] == target){
        return i;
    }

    return binarySearch(arr, target, i+1);
}

void binaryOccurent(vector<int> arr,int target,int i) {
     if(i == arr.size()) {
        return;
    }

    if(arr[i] == target){
        cout << i << endl;
    }

    binaryOccurent(arr, target, i+1);
}

int ferq(int n,int i,int st,string str){
   if(n == 0 || n == 1) {
       return n;
   }

   int res = ferq(n-1, i+1, st, str) + 1;
   int res2 = 0;
   if(str[st] == str[i+1]) {
     ferq(n-1, i+1, st+1, str);
     res2++;
   }

   return res2;
//   if(str[i] == str[st]) {
//       return ferq(n-1, i+1, st, str) + ferq(n-1, i+1, st+1, str);
//   } else {
//       return ferq(n-1, i+1, st, str);
//   }
}

int countNum(int i,int n,int ans){
   int range = (n * 9) + n;
   int bitmask = i & 1;

   if(bitmask != 1) {
      ans++;
   }

   if(range < n) {
        return ans;
   }

   return countNum(i+1, n, ans);
 
}
int main() {

    vector<int> arr = {1,2,3,4,5};
    vector<int> arr2 = {3,0,4,5,6,0,7,0,0};
//    cout << binarySearch(arr, 15, 0);
//    binaryOccurent(arr2, 2, 0);
//    string str = "abcab";
//    cout << ferq(5,0,0,str);

 cout << countNum(0, 1, 0);

    return 0;
}