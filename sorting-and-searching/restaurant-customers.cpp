#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, int>> events;

    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int total = 0;
    int ans = 0;

    for(int i = 0; i < 2*n; i++){
        total += events[i].second;
        ans = max(total, ans);
    }

    cout << ans;

    return 0;
}