#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];
int no_of_triangles, no_of_vertices, no_of_edges;

bool child(int check,int i){
    for(auto it: g[i]){
        if(it==check)
         return true;
    }
    return false;
}

void count()
{
    for(int i=1;i<=no_of_vertices;i++){
        for(auto it:g[i]){
            for(auto itt:g[i]){
                if(itt!=it && child(itt,it))
                no_of_triangles++;
            }
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
    count();
    cout << "Total no of triangles=" << no_of_triangles/6 << endl;
    return 0;
}
// We can easily calculate the no of any polygon by extending the algorithm
