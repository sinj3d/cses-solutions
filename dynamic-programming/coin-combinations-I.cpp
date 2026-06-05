#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<long long> combinations(x + 1, 0);

    for(int i = 0; i < n; i++) cin >> coins[i];

    for(int c: coins){
        if(c <= x){
            combinations[c] = 1;
        }
    }

    for(int i = 0; i <= x; i++){
        long long total = combinations[i];
        for(int c : coins){
            if(i - c >= 0){
                total += combinations[i - c];
            }
        }
        combinations[i] = total % (long long)(pow(10, 9) + 7);
        
    }

    cout << combinations[x];
    
    return 0;

}