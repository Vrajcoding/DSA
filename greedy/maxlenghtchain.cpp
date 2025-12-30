// lc 646
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int maxchain(vector<pair<int,int>> vec) {
    sort(vec.begin(), vec.end(), compare);

    int maxchain = 1;
    int currEnd = vec[0].second;

    for(int i = 1;i <= vec.size();i++) {
        if(vec[i].first > currEnd) {
            maxchain++;
            currEnd = vec[i].second;
        }
    }

    cout << "max chain = " << maxchain << endl;
    return maxchain;
}
int main() {

    vector<pair<int,int>> vec(5, make_pair(0,0));
    vec[0] = make_pair(5 ,24);
    vec[1] = make_pair(39 ,60);
    vec[2] = make_pair(5 ,28);
    vec[3] = make_pair(27 ,40);
    vec[4] = make_pair(5 ,24);

   maxchain(vec);
    return 0;
}