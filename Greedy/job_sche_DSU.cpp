#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fruit {
    int deadline;
    ll profit;
};

vector<int> parent;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v) {
    parent[Find(u)] = Find(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> f(n);
        int mxDeadline = 0;

        for (int i = 0; i < n; i++) {
            cin >> f[i];
            mxDeadline = max(mxDeadline, f[i]);
        }

        vector<ll> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<Fruit> fruits(n);

        for (int i = 0; i < n; i++) {
            fruits[i] = {f[i], p[i]};
        }

        sort(fruits.begin(), fruits.end(), [](const Fruit &a, const Fruit &b) {
            return a.profit > b.profit;
        });

        parent.resize(mxDeadline + 1);
        for (int i = 0; i <= mxDeadline; i++)
            parent[i] = i;

        ll ans = 0;

        for (auto &fruit : fruits) {
            int slot = Find(fruit.deadline);

            if (slot > 0) {
                ans += fruit.profit;
                Union(slot, slot - 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}