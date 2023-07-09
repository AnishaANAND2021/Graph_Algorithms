#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> gT[N];
stack<int> s; // Step1: create an empty stack

int vis[N];
int visT[N];
int level[N];
vector<vector<int>> scc;
vector<int> cc;

void dfs(int root)
{
    if (vis[root])
        return;
    vis[root] = 1;
    // cout<<root<<' ';
    cc.push_back(root);
    for (auto it : g[root])
    {
        dfs(it);
    }
    s.push(root);
}

void dfsT(int root)
{
    if (visT[root])
        return;
    visT[root] = 1;
    cc.push_back(root);
    for (auto it : gT[root])
    {
        dfsT(it);
    }
}

void transpose(int no_of_vertices)
{
    for (int i = 0; i <= no_of_vertices; i++)
    {
        for (int child : g[i])
        {
            gT[child].push_back(i);
        }
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
        // gT[m].push_back(n);
        g[n].push_back(m);
    }
    // Step 2: do dfs of the graph
    for (int i = 0; i <= no_of_vertices; i++)
    {
        if (vis[i])
            continue;
        // dfs(i);
        // cc.clear();
        dfs(i);
        // scc.push_back(cc);
        // cout<<endl;
    }
    // Step 3: obtain the transpose of the graph
    transpose(no_of_vertices);

    vis[N] = {0};
    // Step4:
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        if (visT[x])
            continue;
        cc.clear();
        dfsT(x);
        reverse(cc.begin(),cc.end());
        scc.push_back(cc);
    }
    sort(scc.begin(),scc.end());
    cout <<"Strongly connected components are :\n";
    for (auto it : scc)
    {
        for (auto i : it)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}