#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
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
        if (isDir)
            l[v].push_back(u);
    }

    void dfs(int src, vector<bool> &vis, stack<int> &s)
    {
        vis[src] = true;

        for (auto v : l[src])
        {
            if (!vis[v])
            {
                dfs(v, vis, s);
            }
        }

        s.push(src);
    }

    void topologiCalsort()
    {
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (vis[i])
                continue;
            dfs(i, vis, s);
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    void indegree(vector<int> &indegrees)
    {
        for (int i = 0; i < V; i++)
        {
            for (auto v : l[i])
            {
                indegrees[v]++;
            }
        }
    }

    void topologicalSort2()
    {
        vector<int> indegrees(V, 0);
        queue<int> q;
        indegree(indegrees);
        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for(auto v : l[curr])
            {
                indegrees[v]--;
                if(indegrees[v] == 0) {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph graph(6, false);

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topologicalSort2();
    return 0;
}