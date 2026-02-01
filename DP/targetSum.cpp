#include<iostream>
#include<vector>
using namespace std;
bool targetSum(vector<int> val,int target) {
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= target;j++) {
            if(val[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j-val[i-1]] + val[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(auto vec : dp) {
        for(auto val : vec) {
            cout << val << " ";
        } 
        cout << endl;
    }
    return dp[n][target] == target;
}
int main() {
    vector<int> val = {4,2,7,1,3};
    int target = 7;

    cout << targetSum(val, target) << endl;

    return 0;
}