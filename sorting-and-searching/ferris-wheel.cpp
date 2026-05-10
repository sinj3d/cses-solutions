#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    vector<int> weights(n);

    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int l = 0, r = n-1;
    int total = 0;

    while(l <= r){
        if(weights[r] + weights[l] <= x){
            total++;
            l++;
            r--;
        } else{
            total++;
            r--;
        }
    }

    if(r == l){
        total++;
    }

    cout << total;

    return 0;
}