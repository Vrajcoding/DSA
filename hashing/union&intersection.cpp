#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
void unions(vector<int> ans1,vector<int> ans2){
    unordered_set<int> un;

    for(int el : ans1) {
        un.insert(el);
    }

    for(int el : ans2) {
        un.insert(el);
    }

    for(int el : un) {
        cout << el << " ";
    }
    cout << endl;
}

void intersection(vector<int> arr1,vector<int> arr2){
    unordered_set<int> un;

    for(int el : arr1) {
        un.insert(el);
    }

    for(int el : arr2){
        if(un.find(el) != un.end()) {
            cout << el << " ";
            un.erase(el);
        }
    }
}


int main()
{
  vector<int> ans1 = {7,3,9};
  vector<int> nums = {1,1,1,2,6,3,9,2,9,4};
  unordered_map<int, int> mp;
  map<int, int> val;



  for(int i = 0;i < nums.size();i++){
    mp[nums[i]]++;
  }

  for(auto m : mp) {
    cout << m.first << ":" << m.second << endl;
  }
  
    return 0;
}