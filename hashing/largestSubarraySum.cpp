#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int maxSubarray(vector<int> vec) {
    int currSum = 0;
    unordered_map<int,int> m;
    int maxLength = 0;

    for(int i = 0;i < vec.size();i++) {
        currSum += vec[i];
        if(m.count(currSum)) {
          int length = i - m[currSum];  
          maxLength = max(maxLength, length);
        } else {
            m[currSum] = i;
        }
    }
  return maxLength;
}

int main()
{
   vector<int> arr = {15,-2,2,-8,1,7,10};
   cout << maxSubarray(arr) << endl;
    return 0;
}