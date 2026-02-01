#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
class Graph
{
    int V;
    list<pair<int, int>> *l;
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back(make_pair(v, w));
        l[v].push_back(make_pair(u, w));
    }

    void prims(int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(V, false);
        int totalCost = 0;

        pq.push(make_pair(0, src));
        while(!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(!vis[u]) {
                vis[u] = true;
                totalCost += wt;
                for(auto n : l[u]) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }

            
        }

        cout << "Total cost is :" << totalCost;
    }

    
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

     graph.prims(0);
    return 0;
}