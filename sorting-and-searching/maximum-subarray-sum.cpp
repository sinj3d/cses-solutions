#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x;
    cin >> x;
    long long total = x;
    long long best = x;

    for(int i = 1; i < n; i++){
        cin >> x;

        total = max(total + x, (long long)x);
        best = max(best, total);

    }

    cout << best;

    return 0;
}