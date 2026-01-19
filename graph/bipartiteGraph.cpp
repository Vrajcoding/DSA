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

   bool bipartite() {
    queue<int> Q;
    // vector<bool> vis(V, false);
    vector<int> color(V, -1);
    Q.push(0);
    // vis[0]= true;
    color[0] = 0;

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();

        for(auto v : l[curr]){
            if(color[v] == -1) {
                // vis[v] = true;
                Q.push(v);
                color[v] = !color[curr];
            } else {
                if(color[v] == color[curr]) {
                    return false;
                }
            }
        }
    }
    return true;
   }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << graph.bipartite() << endl;


    return 0;
}