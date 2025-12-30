#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int> coins,int V){
 
    int n = coins.size();
    int ans = 0;

    for(int i = n;i >= 0 && V > 0;i--) {
        if(V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }

    cout << "max is :" << ans << endl;
    return ans;
}
int main() {

    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    coinChange(coins, 590);
    return 0;
}