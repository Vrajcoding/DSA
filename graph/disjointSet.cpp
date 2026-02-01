#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
    vector<int> rank;
    vector<int> par;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            rank.push_back(0);
            par.push_back(i);
        }
    }

    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }

        return par[x] = find(par[x]); // path compressor
    }

    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }
        else
        {
            par[parA] = parB;
        }
    }
};

int main()
{
    DisjointSet dt(6);
    dt.unionByRank(0, 2);
    cout << dt.find(2) << endl;
    dt.unionByRank(1, 3);
    dt.unionByRank(2, 5);
    dt.unionByRank(0, 3);
    cout << dt.find(2) << endl;
    dt.unionByRank(0, 4);
    return 0;
}