#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fruit {
    int deadline;
    ll profit;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<Fruit> fruits(n);

        for (int i = 0; i < n; i++)
            cin >> fruits[i].deadline;

        for (int i = 0; i < n; i++)
            cin >> fruits[i].profit;

        sort(fruits.begin(), fruits.end(),
            [](const Fruit &a, const Fruit &b) {
                return a.deadline < b.deadline;
            });

        priority_queue<
            ll,
            vector<ll>,
            greater<ll>
        > pq;

        for (auto &fruit : fruits) {
            pq.push(fruit.profit);

            if ((int)pq.size() > fruit.deadline)
                pq.pop();
        }

        ll ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}