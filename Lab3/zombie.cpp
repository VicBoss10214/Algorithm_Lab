#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> g(n);
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            cin >> g[i];
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'Z') {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (g[nx][ny] == '#')
                    continue;

                if (dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dist[i][j] << " ";
            }
            cout << '\n';
        }
    }
}