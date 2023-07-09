#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

int vis[N];
int level[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int vertices, edges;
    cout<<"Enter the number of nodes : ";
    cin >> vertices ;
    cout<<"Enter the number of edges : ";
    cin>> edges;
    vector<pair<int, pair<int, int>>> edge;
    cout<<"Enter the adjacent nodes and their weigth ";
    for (int i = 0; i < edges; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edge.push_back({wt, {u, v}});
    }
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= vertices; i++)
        make(i);
    int total_cost = 0;
    cout<<"Minimum spanning tree is : \n";
    for (auto &e : edge)
    {
        int wt = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        cout<<u<<' '<<v<<endl;
    }
    cout<<"Total cost : "<<total_cost<<endl;
    return 0;
}

// Time Complexity=O(alpha(n)) <-amortrized time complexity
//  alpha(n) Reverse Ackerman function