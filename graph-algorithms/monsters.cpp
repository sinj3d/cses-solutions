#include <bits/stdc++.h>

using namespace std;

int MAXINT = (1U << 31) - 1;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    pair<int, int> start;
    vector<pair<int, int>> monsters;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            map[i][j] = c;
            switch(c){
                case 'M': monsters.push_back({i,j}); break;
                case 'A': start = {i,j}; break;
            }
        }
    }

    auto isValid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m && map[x][y] != '#';
    };

    queue<pair<int, int>> bfs;
    vector<vector<int>> monsterTimes(n, vector<int>(m, MAXINT));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dc[4] = {'U', 'D', 'L', 'R'};
    
     //build map of where monsters could be at a time with multisource BFS
    for(auto i: monsters){
        bfs.push(i);
        monsterTimes[i.first][i.second] = 0;
    }

    while(!bfs.empty()){
        auto coord = bfs.front(); bfs.pop();
        
        for(int i = 0; i < 4; i++){
            int x = coord.first + dx[i];
            int y = coord.second + dy[i];

            if (isValid(x, y)) {
                if (monsterTimes[coord.first][coord.second] + 1 < monsterTimes[x][y]) {
                    monsterTimes[x][y] = monsterTimes[coord.first][coord.second] + 1;
                    bfs.push({x, y});
                }
            }
        }
    }

    //single source BFS for the player. check both is move is valid and whether it crosses a monster
    
    vector<vector<pair<char, int>>> playerMap(n, vector<pair<char, int>>(m, {'X', MAXINT})); //pair encodes both direction it camefrom and time it took to get there
    bfs.push(start);
    playerMap[start.first][start.second] = {'X', 0};
    bool foundExit = false;
    pair<int, int> exit;

    while(!bfs.empty()){
        auto coord = bfs.front(); bfs.pop();
        if(coord.first == 0 || coord.first == n - 1 || coord.second == 0 || coord.second == m - 1){
            exit = {coord.first, coord.second};
            foundExit = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            int x = coord.first + dx[i];
            int y = coord.second + dy[i];

            if (isValid(x, y)) {
                if (playerMap[coord.first][coord.second].second + 1 < playerMap[x][y].second) {
                    playerMap[x][y].second = playerMap[coord.first][coord.second].second + 1;
                    if(playerMap[x][y].second < monsterTimes[x][y]) {
                        playerMap[x][y].first = dc[i];
                        bfs.push({x, y});
                    }
                }
            }
        }
    }

    if(!foundExit){
        cout << "NO\n";
        return 0;
    }

    pair<int, int> cur = exit;
    string path;
    while(cur != start){
        char d = playerMap[cur.first][cur.second].first;
        path += d;
        if(d == 'D') cur.first -= 1;
        else if(d == 'U') cur.first += 1;
        else if(d == 'L') cur.second += 1;
        else if(d == 'R') cur.second -= 1;
    }

    cout << "YES\n";
    cout << path.size() << "\n";
    for(auto it = path.rbegin(); it != path.rend(); it++){
        cout << *it;
    }

    return 0;
}