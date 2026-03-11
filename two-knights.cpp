#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int k = 1; k <= n; k++){
        
        long long res = 1LL*k*k*(k*k-1)/2 -1*(k-1)*(k-2)*4LL;
        cout << res << "\n";
    }

    return 0;
}