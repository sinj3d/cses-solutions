#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    
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
    vector<int> cameFrom(n + 1, -1);

    queue<int> bfs;
    bfs.push(1);
    seen[1] = true;

    bool found = false;
    while(!bfs.empty()){
        int cur = bfs.front(); bfs.pop();

        if(cur == n){
            found = true;
            break;
        }

        for(int i : adj[cur]){
            if(seen[i]) continue;
            bfs.push(i);
            seen[i] = true;
            cameFrom[i] = cur;
        }

    }

    if(!found){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int cur = n;
    vector<int> outputReversed; outputReversed.push_back(n);
    while(cur != 1){
        outputReversed.push_back(cameFrom[cur]);
        cur = cameFrom[cur];
    }

    cout << outputReversed.size() << "\n";

    for(auto it = outputReversed.rbegin(); it != outputReversed.rend(); ++it){
        cout << *it << " ";
    }

}