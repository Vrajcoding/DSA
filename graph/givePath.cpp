#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
class Graph
{
    int V;
    list<int> *l;
    list<pair<int, int>> *lw;

    void dfsHelper(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";

        list<int> neighbours = l[u];
        for (auto v : neighbours)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void bfsHelper(int src, vector<bool> v) // 0(V + E)
    {
        queue<int> q;
        q.push(src);
        v[src] = true;

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            list<int> neighbour = l[curr];
            for (int ver : neighbour)
            {
                if (!v[ver])
                {
                    v[ver] = true;
                    q.push(ver);
                }
            }
        }
        cout << endl;
    }

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
        lw = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isPathHelper(int curr, int destination, vector<bool> &vis)
    {
        queue<int> Q;
        Q.push(curr);
        vis[curr] = true;

        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            if (node == destination)
            {
                return true;
            }

            list<int> neighbours = l[node];
            for (int v : neighbours)
            {
                if (!vis[v])
                {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
        return false;
    }

    bool ispath(int curr, int destination)
    {
        vector<bool> vis(V, false);
        return isPathHelper(curr, destination, vis);
    }
};

int main()
{
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    // graph.dfs();

    cout << graph.ispath(0, 5) << endl;

    return 0;
}