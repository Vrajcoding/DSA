#include<iostream>
#include<vector>
using namespace std;
class Heap {
    vector<int> vec;
    public:

    void push(int val) {
        vec.push_back(val);
        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while(x > 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }
    void helpfy(int i) {

        if(i >= vec.size()) {
            return;
        }
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
           maxIdx = l;
        }

        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }

        if(maxIdx != i) {
            swap(vec[maxIdx], vec[i]);
            helpfy(maxIdx);
        }
    }

    void pop() {
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        helpfy(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }

};


int main() {

    Heap heap;
    heap.push(100);
    heap.push(350);
    heap.push(40);
    heap.push(120);

    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
    return 0;
}