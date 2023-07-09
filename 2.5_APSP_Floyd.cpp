#include <bits/stdc++.h>
using namespace std;

const int N = 1e2;
const int INF = 1e9;
vector<pair<int, int>> g[N];
int dist[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    char d;
    cout << "Enter 'Y' if your graph is directed else 'N' : ";
    cin >> d;
    int no_of_vertices, no_of_edges;
    cout << "Enter the no of vertices : ";
    cin >> no_of_vertices;
    cout << "Enter the no of edges : ";
    cin >> no_of_edges;
    cout << "Enter the adjacent edges : \n";
    while (no_of_edges--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        if (d == 'N')
            g[m].push_back({n, w});
        g[n].push_back({m, w});
        dist[n][m] = w;
    }
    for (int k = 1; k <= no_of_vertices; k++)
    {
        for (int i = 1; i <= no_of_vertices; i++)
        {
            for (int j = 1; j <= no_of_vertices; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            if (dist[i][j] < INF && i != j)
                cout << "Shortest distance between " << i << " and " << j << " = " << dist[i][j] << endl;
        }
    }
    return 0;
}
// works for -ve weights but doesn't work for negative weighted cycle
