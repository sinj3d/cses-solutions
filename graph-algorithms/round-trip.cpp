#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, vector<bool>& seen, vector<int>& cameFrom, int prev, int cur){
    if(seen[cur]) return 0;
    cameFrom[cur] = prev;
    seen[cur] = true;
    for(int i : adj[cur]){
        if(seen[i] && i != prev) return cur;
        if(seen[i]) continue;
        int dest = dfs(adj, seen, cameFrom, cur, i);
        if(dest) return dest;
    }
    return 0;
}

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

    vector<bool> seen(n + 1, false);
    vector<int> cameFrom(n + 1);

    int dest;
    for(int i = 1; i <= n; i++){
        if(seen[i]) continue;
        dest = dfs(adj, seen, cameFrom, 0, i);
        if(dest) break;
    }

    if(!dest){ 
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int cur = dest;
    do{ 
        path.push_back(cur);
        cur = cameFrom[cur];
    } while(cur != 0 && cur != dest);
    if(cur != dest) path.push_back(dest);

    cout << path.size() << "\n";
    for(int i : path){
        cout << i << " ";
    }

}