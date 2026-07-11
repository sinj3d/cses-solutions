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
    
    vector<bool> seen(n + 1, false);
    vector<vector<int>> connectedComponents;

    for(int i = 1; i < n + 1; i++){
        if(seen[i]){
            continue;
        }
        queue<int> bfs;
        bfs.push(i);
        vector<int> component;
        component.push_back(i);
        seen[i] = true;
        while(!bfs.empty()){
            int a = bfs.front(); bfs.pop();
            for(int b : adj[a]){
                if(!seen[b]){
                    bfs.push(b);
                    seen[b] = true;
                    component.push_back(b);
                }
            }
        }
        connectedComponents.push_back(component);
        
    }

    cout << connectedComponents.size() - 1 << "\n";

    for(int i = 0; i < connectedComponents.size() - 1; i++){
        cout << connectedComponents[i][0] << " " << connectedComponents[i + 1][0] << "\n";
    }

    return 0;
}