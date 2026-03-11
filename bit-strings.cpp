#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long res = 1;
    long long base = 2;
    long long mod = 1000000007;

    while (n > 0){

        if(n % 2 == 1) res = (res * base) % mod;

        base = base * base % mod;

        n /= 2;
    }

    cout << res << '\n';

    return 0;
}