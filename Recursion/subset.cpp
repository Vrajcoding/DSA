#include<bits/stdc++.h>
using namespace std;
void printSubset(string str, string subset) {
    if(str.size() == 0) {
        cout << subset << endl;
        return;
    }
    char ch = str[0];


    // yes choice
    printSubset(str.substr(1, (str.size() - 1)), subset+ch);
    // no choice
    printSubset(str.substr(1, str.size() - 1), subset);
}


void permutation(string str, string ans) {
      int n = str.size();
      if( n == 0) {
        cout << ans << "\n";
        return;
      }
    for(int i = 0;i < str.size();i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);
        permutation(nextStr , ans + ch);
    }
}
int main() {
   string str = "abc";
   string subset = " ";

//    printSubset(str, subset);
   permutation(str, subset);
    return 0;
}