#include <bits/stdc++.h>

using namespace std;

int solve(int x, vector<int>& coins);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    vector<int> combinations(x + 1, -1);
    combinations[0] = 0;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    for(int i = 1; i <= x; i++){
        int best = INT_MAX;
        for(int c : coins){
            if(i - c >= 0 && combinations[i - c] != -1){
                best = min(best, combinations[i - c]);
            }
        }
        if(best == INT_MAX){
            combinations[i] = -1;
        } else{
            combinations[i] = best + 1;
        }
    }

    cout << combinations[x];

    return 0;

}
