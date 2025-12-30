#include<iostream>
#include<list>

using namespace std;
template<class T>
class Stack {
    list<T> ll;
public:
    void push(T val) {
        ll.push_front(val);
    }    

    void pop() {
        if(isEmpty()) {
            cout << "stack is empty" << endl;
            return;
        }
        ll.pop_front();
    }

    T top() {
        return ll.front();
    }

    bool isEmpty() {
        return ll.size() == 0;
    }
};

int main() {
 
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}