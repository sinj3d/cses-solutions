#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    for(int i = 0; i < n; i++){
        int t; cin >> t;
        tickets.insert(t);
    }

    for(int i = 0; i < m; i++){

        int t;
        cin >> t;

        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()){
            cout << -1;
        }
        else{
            cout << *prev(it);
            tickets.erase(prev(it));
        }
        cout << "\n";
    }

    return 0;
}