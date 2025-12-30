#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isDuplicate(string s) {

    stack<char> st;
    for(int i = 0;i < s.size();i++) {
        char ch = s[i];
        // non-closing
        if(ch != ')') {
            st.push(ch);
        } else {
            if(st.top() == '(') {
                return true;
            } 

            while(st.top() != '(') {
                st.pop();
            }

            st.pop();
        }
    }

    return false;
}
int main() {

    string str1 = "((a+b))";
    string str2 = "((a+b)+(c+d))";
    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}