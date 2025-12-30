#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
int spilteArray(vector<int> nums,int k) {
    sort(nums.begin(), nums.end(), greater<int> ());
    for(int i = 0;i < nums.size();i++) {
        cout << nums[i] << " ";
    }
        int ans = 0;
        for(int i = 1;i <= k;i++) {
            ans += nums[i-1];
        }

        return ans;
}
int main() {
 vector<int> nums = {1,4,4};
 cout << spilteArray(nums, 3);

    return 0;
}