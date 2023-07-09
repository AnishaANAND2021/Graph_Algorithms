#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];


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
    
    return 0;
}