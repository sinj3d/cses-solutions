#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    multiset<int> top;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        //if multiset, use .upper_bound instead of upper_bound(begin, end). Tree structure speeds up to log n
        multiset<int>::iterator it = top.upper_bound(k);

        if(it == top.end()){
            top.insert(k);
        } else{
            top.erase(it);
            top.insert(k);
        }
    }

    cout << top.size();

    return 0;

}