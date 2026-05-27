#include <bits/stdc++.h>

using namespace std;

struct FenwickTree{

    vector<long long> bit;
    int n;

    FenwickTree(int n): n(n), bit(n + 1, 0){};

    void update(int idx, long long delta){
        for(; idx <= n; idx += idx & (-idx)){
            bit[idx] += delta;
        }
    }

    long long sum(int idx){
        long long total = 0;
        for(; idx > 0; idx -= idx & (-idx)){
            total += bit[idx];
        }
        return total;
    }

    long long sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    FenwickTree ft(n);
    vector<long long> original;

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        original.push_back(x);
        ft.update(i + 1, original[i]);
    }

    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            long long k, u;
            cin >> k >> u;
            ft.update(k, (u - original[k - 1]));
            original[k-1] = u;

        }
        if(type == 2){
            int a, b;
            cin >> a >> b;
            cout << ft.sum(a, b) << "\n";
        }
    }

    return 0;
}