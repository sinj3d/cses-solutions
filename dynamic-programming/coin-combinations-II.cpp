#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    vector<long long> combinations(x + 1, 0);
    combinations[0] = 1;

    for(int i = 0; i < n; i ++){
        cin >> coins[i];
    }

    for(int c: coins){
        for(int i = c; i <= x; i++){
            combinations[i] = (combinations[i] +  combinations[i-c]) % (long long)(1e9 + 7);
        }
    }

    cout << combinations[x];

    return 0;

}