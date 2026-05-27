#include <bits/stdc++.h>

using namespace std;

struct FenwickTree{

    vector<long long> bit;
    int n;

    FenwickTree(int n): n(n) bit(n + 1, 0){};

    void update(int l, int r, int delta){
        for(; idx < n; idx += idx & (-idx)){
            bit[idx] += delta;
        }
    }

    void sum(int r){
        int total = 0;
        for(; r > 0; r -= r &(-r)){
            total += bit[r];
        }
    }

    void sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
    


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


}