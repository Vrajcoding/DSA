#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxActivites(vector<int> st,vector<int> end) {
    // if the end is sorted othrwise sort it;
    cout << "A0" << "\n";
    int count  = 1;
    int currEnd = end[0];

    for(int i = 1;i <= st.size();i++) {
        if(st[i] >= currEnd) {
            cout << "A" << i << "\n";
            count++;
            currEnd = end[i];
        }
    }

    return count;
}

bool compare(pair<int, int> p1,pair<int, int> p2) {
    return p1.second < p2.second; // ascending order
    // return p1.second > p2.second; // desecnding order
}

int main() {
// vector<int> st = {1,3,0,5,8,5};
// vector<int> end = {2,4,6,7,9,9};

// cout << maxActivites(st ,end) << endl;

 vector<pair<int, int>> activity(3, make_pair(0 ,0));
 activity[0] = make_pair(0,9);
 activity[1] = make_pair(1,2);
 activity[2] = make_pair(2,4);
 for(int i = 0;i < activity.size();i++) {
    cout << activity[i].first << " ," << activity[i].second << endl;
 }

 sort(activity.begin(), activity.end(), compare);

 cout << "--------sorted--------\n";
 for(int i = 0;i < activity.size();i++) {
    cout << activity[i].first << " ," << activity[i].second << endl;
 }
    return 0;
}