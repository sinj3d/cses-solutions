#include <bits/stdc++.h>

using namespace std;

long long INF = (1e18);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for(int i = 0; i < m; i ++){
        int a, b, x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x});

    }

    vector<vector<int>> radj(n + 1);
    for (auto& [a, b, x] : edges) {
        radj[b].push_back(a);
    }

    vector<bool> canReachN(n + 1, false);
    queue<int> q;
    q.push(n);
    canReachN[n] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : radj[cur]) {
            if (!canReachN[nxt]) {
                canReachN[nxt] = true;
                q.push(nxt);
            }
        }
    }

    vector<long long> distance(n + 1, INF);
    distance[1] = 0;
    bool hasCycle = false;
    for (int round = 1; round <= n; round++) {
        bool changed = false;
        for (auto& [a, b, x] : edges) {
            if (distance[a] < INF && distance[a] + x < distance[b]) {
                distance[b] = distance[a] + x;
                changed = true;
                if (round == n && canReachN[b]) hasCycle = true;
            }
        }
        if (!changed) break;
    }

    if(hasCycle){
        cout << -1;
        return 0;
    }

    cout << -distance[n];
    return 0;
}