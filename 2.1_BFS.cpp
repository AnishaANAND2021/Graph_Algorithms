#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];

void bfs(int index, int no_of_vertices) 
{char d;
    cout << "Enter 'Y' if your graph is directed ,otherwise 'N' : ";
    cin >> d;
    cout << "BFS traversal is : ";
    queue<int> q;
    q.push(index);
    vis[index] = 1;
    level[index] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int child : g[x])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = 1;
            level[child] = level[x] + 1;
        }
    }
    cout << endl;
}

int main()
{
    int no_of_vertices, no_of_edges;
    cout << "Enter the no of vertices : ";
    cin >> no_of_vertices;
    cout << "Enter the no of edges : ";
    cin >> no_of_edges;
    cout<<"Enter the adjacent edges : \n";
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
    bfs(root, no_of_vertices); 
    cout << "Levels of the vertices :\n ";
    for (int i = 1; i <= no_of_vertices; i++)
    {
        cout << "     " << i << " : " << level[i] << endl;
    }
    return 0;
}