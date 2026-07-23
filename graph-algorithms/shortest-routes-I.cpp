#include <bits/stdc++.h>

using namespace std;

long long INF = (1ULL << 63) - 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); //first number in pair is the city, second is the weight

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});

    }

    vector<long long> distances(n + 1, INF);
    distances[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //first number in pair is distance, second is the city
    pq.push({0, 1});

    while(!pq.empty()){
        auto [cur_dist, city] = pq.top(); pq.pop();
        if(cur_dist > distances[city]) continue;

        for(auto i: adj[city]){
            long long tentative_dist = cur_dist + i.second;
            if(tentative_dist < distances[i.first]){
                distances[i.first] = tentative_dist;
                pq.push({tentative_dist, i.first});
            }
        }

    }

    for(int i = 1; i <= n; i++){
        cout << distances[i] << " ";
    }

    return 0;

}