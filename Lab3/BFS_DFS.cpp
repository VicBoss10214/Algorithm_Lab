#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &vis, int start)
{
    queue<int> q;
    q.push(start);
    vis[start]=true;

    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();

        for(int next:adj[node])
        {
            if(!vis[next])
            {
                vis[next]=true;
                q.push(next);
            }
        }
    }

}

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int node)
{
    vis[node]=true;
    cout<<node<<" ";
    for(int next:adj[node])
    {
       if(!vis[next])
       {
         dfs(adj,vis,next);
       }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,vis,1);
}