#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car {
public:
   int idx;
   int distSqr;

   Car(int idx,int distSqr) {
    this->idx = idx;
    this->distSqr = distSqr;
   }

   bool operator < (const Car &obj) const {
    return this->distSqr > obj.distSqr;
   }
};

void carByNear(vector<pair<int,int>> vec,int K) {
    vector<Car> car;

    for(int i = 0;i < vec.size();i++) {
        int distSqr = (vec[i].first * vec[i].first) + (vec[i].second * vec[i].second);
        car.push_back(Car(i, distSqr));
    }

    priority_queue<Car> pq(car.begin(), car.end());

    for(int i = 0;i < K;i++) {
        cout << "Car = " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int,int>> vec;
    vec.push_back(make_pair(3, 3));
    vec.push_back(make_pair(5 ,-1));
    vec.push_back(make_pair(-2, 4));

    carByNear(vec, 3);
    return 0;
}