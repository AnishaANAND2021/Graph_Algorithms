#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N]; // first part of pair is storing index and second part of index is storing weight
vector<int> dist(N, INF);    // initializing all distance to a very large no

int vis[N];

void dijkstra(int root)
{
    set<pair<int, int>> s;
    s.insert({0, root});
    dist[root] = 0;
    while (s.size())
    {
        auto it = *s.begin();
        s.erase(s.begin());
        int vertex = it.second;
        int vertex_dist = it.first;
        if (vis[vertex])
            continue;
        vis[vertex] = 1;
        for (auto it : g[vertex])
        {
            int child = it.first;
            int child_dist = it.second;
            if (child == vertex)
                continue;
            if (dist[vertex] + child_dist < dist[child])
            {
                dist[child] = dist[vertex] + child_dist;
                s.insert({dist[child], child});
            }
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
    cout << "Enter the adjacent vertices and weight of edge of your graph : \n";

    while (no_of_edges--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        g[n].push_back({m, w});
        if (wt == 'N')
            g[m].push_back({n, w});
    }
    int root;
    cout << "Enter the root node : ";
    cin >> root;
    dijkstra(root);
    cout << endl;
    int vertex;
    int exit = 1;
    while (exit)
    {
        cout << "Enter the vertex whose distance is to be calculated : ";
        cin >> vertex;
        cout << "Shortest path of " << vertex << " from " << root << " is : ";
        cout << dist[vertex] << endl;
        cout << "Enter '1' to find distance of other vertices \n      '0' to exit : ";
        cin >> exit;
    }
    return 0;
}
