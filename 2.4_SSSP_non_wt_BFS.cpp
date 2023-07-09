#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (auto it : g[x])
        {
            if (vis[it])
                continue;
            q.push(it);
            level[it] = level[x] + 1;
        }
    }
}

int main()
{
    char wt;
    cout << "Enter 'Y' if your graph is weighted else 'N' : ";
    cin >> wt;
    int no_of_vertices, no_of_edges;
    cout << "Enter the no of vertices : ";
    cin >> no_of_vertices;
    cout << "Enter the no of edges : ";
    cin >> no_of_edges;
    cout << "Enter the adjacent vertices of your non-weighted or equal weighted graph : \n";
    while (no_of_edges--)
    {
        int n, m;
        cin >> n >> m;
        if (wt == 'N')
            g[m].push_back(n);
        g[n].push_back(m);
    }
    int root;
    cout << "Enter the root node : ";
    cin >> root;

    bfs(root);
    cout << endl;
    int vertex;
    int exit = 1;
    while (exit)
    {
        cout << "Enter the vertex whose distance is to be calculated : ";
        cin >> vertex;
        cout << "Shortest path of " << vertex << " from " << root << " is : ";
        cout << level[vertex] - level[root] << endl;
        cout << "Enter '1' to find distance of other vertices \n      '0' to exit : ";
        cin >> exit;
    }
    return 0;
}