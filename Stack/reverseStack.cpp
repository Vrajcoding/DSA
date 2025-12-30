#include<iostream>
#include<stack>
using namespace std;
void pushAtbottom(stack<int> &s,int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtbottom(s, val);
    s.push(temp);
}
void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtbottom(s, temp);
}



void printstack(stack<int> s) {
  while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}
int main() {

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    printstack(s);
    reverseStack(s);
    printstack(s);
   

    return 0;
}