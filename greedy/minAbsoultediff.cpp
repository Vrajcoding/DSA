#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int minAb = 0;
    for(int i = 0;i < a.size(); i++) {
        minAb += abs(a[i] - b[i]);
    }


    cout << minAb << endl;

    return 0;
}