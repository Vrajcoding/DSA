// Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

// Input: nums = [4,5,0,1,2,3]
// Output: [4,5,0,1,2,3]
// Explanation: The array ans is built as follows:
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
//     = [4,5,0,1,2,3]

#include<bits/stdc++.h>
using namespace std;
vector<int> buildArray(vector<int>& nums) {
       vector<int> ans;
       for(int i = 0;i < nums.size();i++) {
         ans.push_back(nums[nums[i]]);
       }

       return ans; 
 }


 vector<int> buildArray2(vector<int>& nums){
 int n = nums.size();
        for (int i = 0; i < n; i++) {
            int newVal = nums[nums[i]] % n;
            nums[i] += newVal * n;
        }
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }
        return nums;
}

int main() {
  vector<int> nums = {4,5,0,1,2,3};
  buildArray2(nums);
}