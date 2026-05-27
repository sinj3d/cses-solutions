#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    multiset<int> distances;
    set<int> signs;

    signs.insert(x);
    signs.insert(0);
    distances.insert(x);

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;

        set<int>::iterator upper = signs.upper_bound(p);
        int difference = *upper - *(prev(upper));
        distances.erase(distances.find(difference));
        distances.insert(*upper - p);
        distances.insert(p - *(prev(upper)));
        signs.insert(p);

        cout << *distances.rbegin() << " ";
        
    }

    return 0;
}