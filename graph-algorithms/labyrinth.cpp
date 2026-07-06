#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dirChar[4] = {'U', 'D', 'L', 'R'};

    pair<int, int> A, B;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'A') A = {i, j};
            if(map[i][j] == 'B') B = {i, j};
        }
    }

    vector<vector<char>> cameFrom(n, vector<char>(m, '0'));
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    
    queue<pair<int,int>> bfs; //bfs queue
    bfs.push(A);

    bool found = false;

    while(!bfs.empty()){
        pair<int,int> cur = bfs.front();
        bfs.pop();
        if(cur == B){
            found = true;
            break;
        }
        for(int d = 0; d < 4; d++){
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if(nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
            if(seen[nx][ny] || map[nx][ny] == '#') continue;

            seen[nx][ny] = true;
            cameFrom[nx][ny] = dirChar[d];
            bfs.push({nx, ny});
        }
    }

    if(!found){
        cout << "NO\n";
        return 0;
    }

    string path;
    cout << "YES\n";

    pair<int, int> cur = B;
    while(cur != A){
        char d = cameFrom[cur.first][cur.second];
        path.push_back(d);

        if(d == 'D') cur.first -= 1;
        else if(d == 'U') cur.first += 1;
        else if(d == 'L') cur.second += 1;
        else if(d == 'R') cur.second -= 1;
        
    }

    cout << path.size() <<'\n';
    for(auto it = path.rbegin(); it != path.rend(); ++it){
        cout << *it;
    }

    return 0;


}