#include<iostream>
#include<string>
#include<vector>
using namespace std;
int lcsRec(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    if(n == 0 || m == 0) {
        return 0;
    }

    if(str1[n-1] == str2[m-1]) {
        return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    } else {
        int ans1 = lcsRec(str1.substr(0, n-1), str2);
        int ans2 = lcsRec(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

int lcsMemo(string str1, string str2, vector<vector<int>> dp) {
    int n = str1.size();
    int m = str2.size();

    if(n == 0 || m == 0) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }
    if(str1[n-1] == str2[m-1]) {
        dp[n][m] =  1 + lcsMemo(str1.substr(0, n-1), str2.substr(0, m-1),dp);
    } else {
        int ans1 = lcsMemo(str1.substr(0, n-1), str2,dp);
        int ans2 = lcsMemo(str1, str2.substr(0, m-1),dp);
        dp[n][m]  = max(ans1, ans2);
    }

    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
int main() {
  string str1 = "abcdge";
  string str2 = "abedg";
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

  cout << lcsMemo(str1, str2, dp) << endl;
    return 0;
}