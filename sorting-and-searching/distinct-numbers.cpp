#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin >> n;

    // more concise way to do it

    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << unique(a.begin(), a.end()) - a.begin();

    //initial solution

    // int t = 0;

    // unordered_set<int> seen;

    // for(int i = 0; i < n; i++){

    //     int x;
    //     cin >> x;
    //     seen.insert(x);
    // }

    // cout << seen.size();

}
