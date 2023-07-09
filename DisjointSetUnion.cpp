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
    size[v]=1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v]=find(parent[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b])
           swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    for(int i=1;i<=vertices;i++){
        make(i);
    }
    while(edges--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    return 0;
}

//Time Complexity=O(alpha(n)) <-amortrized time complexity
// alpha(n) Reverse Ackerman function