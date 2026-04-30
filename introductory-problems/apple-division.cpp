#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> weights;

    long long p;

    for(int i = 0; i < n; i++){
        cin >> p;
        weights.push_back(p);
    }

    long long min_diff = pow(2, 32) - 1;

    for(int i = 0; i < pow(2,n); i++){
        long long pool_a = 0;
        long long pool_b = 0;
        for(int t = 0; t < n; t++){
            if((i >> t) & 1){
                pool_a += weights[t];
            } else{
                pool_b += weights[t];
            }
        }
        min_diff = min(min_diff, abs(pool_b - pool_a));
        
    }
    
    cout << min_diff;

}