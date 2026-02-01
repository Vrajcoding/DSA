#include <iostream>
#include <vector>
using namespace std;
int countWays(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }


    return countWays(n-1) + countWays(n-2);
}
 int climbHelper(int n,vector<int> &f) {
         if(n == 0 || n == 1) {
            return 1;
         }

         if(f[n] != -1) {
            return f[n];
         }

        return f[n] = climbHelper(n-1, f) + climbHelper(n-2, f); 
    }

int main()
{
    int n = 4;
    cout << countWays(n) << endl;

    return 0;
}