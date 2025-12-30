#include<iostream>
#include<stack>
using namespace std;

string reverseString(string str) {

    string ans;
    stack<char> s;

    for(int i = 0;i < str.size();i++) {
        char ch = str[i];
        s.push(ch);
    }


    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {

    cout << reverseString("abcd") << endl;

    return 0;
}