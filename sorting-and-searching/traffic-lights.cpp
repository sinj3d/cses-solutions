#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<int> gaps;
    gaps.insert(x);

    for(int i = 0; i < n; i++){

        int p;
        cin >> p;
        lights.insert(p);
        
        auto it = lights.find(p);
        int after = *(next(it));
        int before = *(prev(it));

        int difference = after - before;

        gaps.erase(gaps.find(difference));

        gaps.insert(after - p);
        gaps.insert(p - before);

        cout << *gaps.rbegin() << " ";
    }

    return 0;
}