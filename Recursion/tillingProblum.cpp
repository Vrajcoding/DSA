#include<iostream>
using namespace std;
int tillingProblum(int n) {
    if( n == 0 || n == 1) {
        return 1;
    }

    // vertically
    int ans1 = tillingProblum(n - 1);

    // Horizontaliy
    int ans2 = tillingProblum(n - 2);

    return ans1 + ans2;
}
int main() {
    int n = 4;
    cout << tillingProblum(n) << endl;
    return 0;
}