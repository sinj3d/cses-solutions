#include <bits/stdc++.h>

using namespace std;

void searchFill(const vector<vector<char>>& map, vector<vector<bool>>& seen, int i, int j){
    if(map[i][j] == '#' || seen[i][j] == true){
        return;
    } else{
        seen[i][j] = true;
        if(i != map.size() - 1) searchFill(map, seen, i + 1, j);
        if(j != map[0].size() - 1) searchFill(map, seen, i, j + 1);
        if(i != 0) searchFill(map, seen, i - 1, j);
        if(j != 0) searchFill(map, seen, i, j - 1);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<bool>> seen(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '.' &&seen[i][j] == false){
                total++;
            }
            searchFill(map, seen, i, j);
        }
    }

    cout << total;

}