#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> dist(n + 1, 0);
    dist[1] = 0;
    vector<tuple<int, int, long long>> edges;

    for(int i = 0; i < m; i++){
        int a, b; long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int cycle_start = -1;
    vector<int> parent(n + 1, -1);

    for(int i = 1; i <= n; i++){
        cycle_start = -1;
        for(auto [a, b, w] : edges){
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                cycle_start = b;
            }
        }
    }

    if(cycle_start == -1){
        cout << "NO\n";
        return 0;
    }

    for(int i = 0;  i < n; i++) cycle_start = parent[cycle_start];

    vector<int> cycle;
    for (int v = cycle_start;; v = parent[v]) {
        cycle.push_back(v);
        if (v == cycle_start && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for(int i: cycle){
        cout << i << " ";
    }
}