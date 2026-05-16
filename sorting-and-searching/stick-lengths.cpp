#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> ps(n);

    for(int i = 0; i < n; i++) cin >> ps[i];

    sort(ps.begin(), ps.end());

    int median = ps[ps.size()/2];
    long long total = 0;

    for(int i = 0; i < n; i++) total += abs(ps[i] - median);

    cout << total;

    return 0;


}