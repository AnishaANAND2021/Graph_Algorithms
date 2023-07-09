#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
vector<int> c;
vector<vector<int>> cc;

void dfs(int root)
{
    if (vis[root])
        return;
    vis[root] = 1;
    c.push_back(root);
    for (int i : g[root])
    {
        dfs(i);
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
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
    int root;
    cout << "Enter the root node : ";
    cin >> root;
    for (int i = 1; i <= no_of_vertices; i++)
    {
        c.clear();
        if (vis[i])
            continue;
        dfs(i);
        cc.push_back(c);
    }
    cout << "No of connected components = " << cc.size();
    cout << "\nConnected components : \n";
    for (auto c : cc)
    {
        for (auto i : c)
            cout << i << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}