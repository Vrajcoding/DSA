#include <iostream>
#include<string>
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

    void dfs(int src,int dest,vector<bool> &vis,string &path){
        if(src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        for(auto v : l[src]) {
            if(!vis[v]) {
               dfs(v, dest, vis, path); 
            }
        }

        path = path.substr(0, path.size() - 1);
        vis[src]= false;
    }

    void printAllPath(int src,int dest) {
        vector<bool> vis(V, false);
        string path = "";

        dfs(src,dest,vis,path);
    }

 
};

int main()
{
    Graph graph(6, false);

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPath(5, 1);
    return 0;
}