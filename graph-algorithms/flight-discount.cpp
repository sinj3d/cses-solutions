#include <bits/stdc++.h>

using namespace std;

long long INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int a, b; long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<array<long long, 2>> dist(n + 1, {INF, INF});
    dist[1] = {0, false};

    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<>> pq; //first number is distance, second is city, third is whether discount is used
    pq.push({0, 1, false});

    while(!pq.empty()){
        auto [d, u, used] = pq.top(); pq.pop();
        if(d > dist[u][used]) continue;

        for(auto [v, w] : adj[u]){
            if(d + w < dist[v][used]){
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            if(!used && d + w / 2 < dist[v][1]){
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";

}