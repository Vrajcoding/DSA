
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void InterLeave(queue<int> &org){ 
    stack<int> s;

    while(!org.empty()) {
        s.push(org.front());
        org.pop();
    }

    while(!s.empty()) {
        org.push(s.top());
        s.pop();
    }
}
int main() {

    queue<int> org;

    for(int i = 1;i <= 5;i++) {
        org.push(i);
    }

    InterLeave(org);

    
    for(int i = 1;i <= 5;i++) {
       cout << org.front() << " ";
       org.pop();
    }

    return 0;
}