#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;s[i] != '\0';i++) {
            //opening
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } // closing 
            else {

              if(st.empty()) {
                return false;
              }

              char top = st.top();
              if((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}') ) {
                st.pop();
              } else {
                return false;
              }
            }  
        }

        if(!st.empty()) {
            return false;
        }

        return true;
    }
};