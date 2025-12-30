#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextGreter(vector<int> arr,vector<int> ans) {
    int n = arr.size() - 1;
    stack<int> s;

    s.push(arr[n]);
      ans[n] = -1;
    for(int i = n-1;i >= 0;i--) {
        int currValue = arr[i];

        while(!s.empty() && currValue >= s.top()) {
            s.pop();
        }

        
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(currValue);

    }

    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
}

int main() {

    vector<int> arr = {1,2,1};
    vector<int> ans = {0,0,0};

    nextGreter(arr,ans);
    return 0;
}