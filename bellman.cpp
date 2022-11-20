#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool finalCheck(vector<node> edges, vector<int> dist)
{

    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;

    vector<node> edges;
    cout << "enter n and m" << endl;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cout << "enter u v wt" << endl;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    int inf = 1000000;
    vector<int> dist(n, inf);
    cout
        << "enter source";
    int src;
    cin >> src;
    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    if (finalCheck(edges, dist))
    {
        cout << "correct h";
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " , ";
        }
    }

    else
    {
        cout << "negative h";
    }
}
