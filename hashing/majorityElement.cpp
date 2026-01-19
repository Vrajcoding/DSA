#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void freq(vector<int> nums) {
    int n = nums.size();
    unordered_map<int,int> m;

    for(int i = 0;i < n;i++) {
        if(m.count(nums[i]) != 0) {
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        }
    }

    for(auto p: m) {
        if(p.second > (n/3)){
            cout << p.first << " ";
        }
    }

    cout << endl;
}


int main()
{
  vector<int> vc = {1,3,2,5,1,3,1,5,1};
  vector<int> nc1 = {1,2};
  freq(nc1);
  
    return 0;
}