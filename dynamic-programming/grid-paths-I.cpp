#include<bits/stdc++.h>

using namespace std;

// it works here, but long long is almost always better than int, just in case of OOB error

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> combinations(n + 1, vector<int>(n + 1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    if(grid[n - 1][n - 1] != '*'){
        combinations[n - 1][n - 1] = 1;
    }

    for(int row = n - 1; row >= 0; row--){
        for(int col = n - 1; col >= 0; col--){
            if(grid[row][col] != '*'){
                combinations[row][col] += (combinations[row + 1][col] + combinations[row][col + 1]) % (long long)(1e9 + 7);
            }
        }
    }

    cout << combinations[0][0];


    return 0;

}