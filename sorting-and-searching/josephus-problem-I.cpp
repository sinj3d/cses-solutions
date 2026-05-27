#include <bits/stdc++.h>

using namespace std;

vector<int> bit;
int n;

void init_bit(int n){
    for(int i = 0; i < n; i++){
        update(i, 1);
    }
}

int update(int i, int val){
    for(; i <= n; i += (i & -i)){
        bit[i] += val;
    }
}

int find_kth(int k){
    int pos = 0;
    for (int i = __lg(n); i >= 0; i--) {
        int next = pos + (1 << i);
        if (next <= n && bit[next] < k) {
            pos = next;
            k -= bit[next];
        }
    }
    return pos + 1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    bit.assign(n + 1, 0);
    init_bit(n);

    int pos = 1;

    for(int i = 0; i < n; i++){
        pos = ((pos - 1 + k) mod m) + 1

    }




}
