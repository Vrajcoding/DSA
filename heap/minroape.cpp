#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int miniMumcost(vector<int> vec) {
   priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
   int cost = 0;
   while(pq.size() > 1) {
    int min1 = pq.top();
    pq.pop();
    int min2 = pq.top();
    pq.pop();
    cost += min1 + min2;
    pq.push(min1 + min2);
   }

   return cost;
}

int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            cout << x << " ";
            
            int y = pq.top();
            pq.pop();
            cout << y << " ";

            
             int diff = x - y;
             pq.push(diff);
            
            cout << endl;
        }

        return pq.top();
    }

int main() {
    vector<int> vec = {2,7,4,1,8,1};
    cout << lastStoneWeight(vec) << endl;
    
    return 0;
}