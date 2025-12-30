#include<iostream>
#include<vector>
using namespace std;
// leetcode 645 dismatch value
int main() {

     vector<int> nums = {1,2,1};
  int n = nums.size();  
  vector<int> temp(n+1, 0);
  vector<int> ans;
    for(int i = 1;i <= n;i++) {
         temp[nums[i-1]]++;
    }


     for(int i = 1;i <= n;i++) {
        if(temp[i] == 2) {
            ans.push_back(i);
        }
    }

    for(int i = 1;i <= n;i++) {
       if(temp[i] == 0) {
         ans.push_back(i);
       } 
    }

   
 cout << ans[0] << " " << ans[1] << endl;
 return 0;
}