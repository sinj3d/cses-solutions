#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> team(n + 1, 0); // 0 is not seen, 1 or 2 is assigned to a team;

    bool possible = true;

    for(int i = 1; i <= n; i++){
        if(!possible) break;
        if(team[i]) continue;

        queue<int> bfs;
        bfs.push(i);
        team[i] = 1;

        while(!bfs.empty()){
            int cur = bfs.front(); bfs.pop();

            for(int a : adj[cur]){
                if(team[a] == team[cur]){
                    possible = false;
                    break;
                }
                if(team[a]) continue;

                bfs.push(a);
                team[cur] == 1 ? team[a] = 2 : team[a] = 1;
            }
            
        }
    }

    if(!possible){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        cout << team[i] << " ";
    }

}