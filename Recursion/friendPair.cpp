#include<iostream>
using namespace std;
int friendPair(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    return friendPair(n-1) + (n-1) * friendPair(n-2);
}

int main() {
    int n = 5;
    cout << friendPair(n) << endl;

    return 0;
}