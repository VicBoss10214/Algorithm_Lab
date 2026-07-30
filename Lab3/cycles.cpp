#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

bool hasCycle;

void dfs(int node, int parent)
{
    vis[node] = true;

    for(int next : adj[node])
    {
        if(!vis[next])
        {
            dfs(next, node);
        }
        else if(next != parent)
        {   
            hasCycle = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        adj.assign(n + 1, {});
        vis.assign(n + 1, false);

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int answer = 0;

        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                hasCycle = false;

                dfs(i, -1);

                if(hasCycle)
                    answer++;
            }
        }

        cout << answer << "\n";
    }
}