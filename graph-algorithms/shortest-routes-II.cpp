#include <bits/stdc++.h>

using namespace std;

long long INF = (1e18);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
    
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b; long long c;
        cin >> a >> b >>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[a][b], c);;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] >= INF ? -1 : dist[a][b]) << "\n";
    }
}