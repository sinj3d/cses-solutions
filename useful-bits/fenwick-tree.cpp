#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    
    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }
    
    long long prefix_sum(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
    
    long long range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    
    // The descent operation for k-th smallest / Josephus-style queries
    int find_kth(long long k) {
        int pos = 0;
        for (int pw = __lg(n); pw >= 0; pw--) {
            int next = pos + (1 << pw);
            if (next <= n && bit[next] < k) {
                pos = next;
                k -= bit[next];
            }
        }
        return pos + 1;
    }
};