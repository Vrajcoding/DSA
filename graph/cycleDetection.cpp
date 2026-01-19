#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
class Graph
{
    int V;
    list<int> *l;
    bool isDir;
public:
    Graph(int V, bool isDir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->isDir = isDir;
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if(isDir)
         l[v].push_back(u);
    }

    void print()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neibours = l[u];
            cout << u << " : ";
            for (int v : neibours)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool dfs(int src, int par, vector<bool> &vis)
    {
        vis[src] = true;
        list<int> neibours = l[src];

        for (auto v : neibours)
        {
            if (!vis[v])
            {
                if (dfs(v, src, vis))
                {
                    return true;
                }
            }
            else
            {
                if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleUnDir()
    {
        vector<bool> vis(V, false);
        return dfs(0, -1, vis);
    }

    bool dfsDir(int src,vector<bool> &vis,vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) {
                if(dfsDir(v, vis, recPath)){
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool isCycledir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V ,false);

        return dfsDir(0, vis, recPath);
    }
};

int main()
{
    Graph graph(4, false);

    graph.addEdge(1, 0);
    // graph.addEdge(0, 2);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << graph.isCycledir() << endl;

    return 0;
}