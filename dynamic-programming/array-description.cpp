#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<long long>> dp(n+1, vector<long long>(m+2, 0));

    if(a[1] == 0)
        for(int v = 1; v <= m; v++) dp[1][v] = 1;
    else
        dp[1][a[1]] = 1;

    for(int i = 2; i <= n; i++){
        int lo = 1, hi = m;
        if(a[i] != 0) lo = hi = a[i];
        for(int v = lo; v <= hi; v++)
            dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;
    }

    long long ans = 0;
    for(int v = 1; v <= m; v++) ans = (ans + dp[n][v]) % MOD;
    cout << ans;
}