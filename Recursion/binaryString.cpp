#include<iostream>
using namespace std;
void binaryString(int n,int lastPosition,string ans) {
     if(n == 0) {
        cout << ans << endl;
        return;
     }

    if(lastPosition != 1){
        binaryString(n-1,0,ans+'0');
        binaryString(n-1,1,ans+'1');
    } else {
        binaryString(n-1,0,ans+'0');
    }
}
int main() {
    string ans = "";
   binaryString(3, 0, ans);

    return 0;
}