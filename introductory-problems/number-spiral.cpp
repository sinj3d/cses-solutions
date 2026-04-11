#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    long long x,y;

    vector<long long> ans(t);

    for(int i = 0; i < t; i++){
        cin >> y;
        cin >> x;

        if(y < x){
            if (x % 2){
                ans[i] = 1LL*x*x - y + 1;
            } else{
                ans[i] = 1LL*(x-1)*(x-1) + y;
            }
        } else{
            if(y % 2){
                ans[i] = 1LL*(y-1)*(y-1) + x;
            } else{
                ans[i] = 1LL*y*y - x + 1;
            }
        }
    }

    for(long long i: ans){
        cout << i << '\n';
    }

    return 0;

}