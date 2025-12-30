#include<queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> Q;
        for(int i = 0;i < tickets.size();i++) {
            Q.push({tickets[i], i});
        }

        int time = 0;

        while(!Q.empty()) {
            auto [num_ticket, idx] = Q.front();

            num_ticket--;
            time++;

            if(idx == k && num_ticket == 0) {
                return time;
            }

           if(num_ticket > 0) {
                 Q.push({num_ticket, idx});
           } 

           Q.pop();
            
        }

        return time;
    }
};