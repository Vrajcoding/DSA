#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int count(vector<int> ans){
    unordered_set<int> s;

    for(int i = 0;i < ans.size();i++){
        s.insert(ans[i]);
    }

    return s.size();
}


int main()
{
  vector<int> vc = {1,3,2,5,1,3,1,5,1};
  cout << count(vc) << endl;
    return 0;
}