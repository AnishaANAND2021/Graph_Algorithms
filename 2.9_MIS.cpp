#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];
vector<int> mis, miS;
int no_of_vertices, no_of_edges;
int m = 1;

void bfs(int root)
{
    queue<int> q;
    q.push(root);

    level[root] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto it : g[x])
        {
            if (!vis[it])
            {
                level[it] = level[x] + 1;
                m = max(m, level[it]);
                q.push(it);
            }
        }
    }
}

void Set()
{
    for (int i = 1; i <= no_of_vertices; i++)
    {
        if (level[i] % 2)
            miS.push_back(i);
        else
        {
            if (i != m)
                mis.push_back(i);
        }
    }
}

int main()
{
    cout << "Enter the no of vertices : ";
    cin >> no_of_vertices;
    cout << "Enter the no of edges : ";
    cin >> no_of_edges;
    cout << "Enter the adjacent edges : \n";
    while (no_of_edges--)
    {
        int n, m;
        cin >> n >> m;
        g[m].push_back(n);
        g[n].push_back(m);
    }
    bfs(1);
    Set();
    cout << "\nMaximal independent sets are: \n";
    for (auto it : mis)
        cout << it << ' ';
    cout << endl;
    for (auto it : miS)
        cout << it << ' ';
    return 0;
}