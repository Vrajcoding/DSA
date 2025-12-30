#include <iostream>
#include <vector>
#include <string>

using namespace std;
int uniquePath(int n,int m,int rows,int cols){
  if(cols == n-1 && rows == m-1) {
    return 1;
  }

  if(cols >= m || rows >= n) {
    return 0;
  }

  // right side
  int val1 = uniquePath(n,m,rows, cols + 1);

  // bottom side
  int val2 = uniquePath(n,m,rows + 1, cols);

  return val1 + val2;

}
int factorial(int n) {
    int fact = 1;
    for(int i = 1;i <= n;i++) {
        fact *= i;
    }

    return fact;
}
int optimizesolution(int n,int m) {
    int total = factorial(n+m) / (factorial(n) * factorial(m));

    return total;
}
int main(){
   int n = 3,m = 7;

   cout << uniquePath(n,m,0,0) << endl;
   cout << optimizesolution(n-1,m-1) << endl;

    return 0;
}