#include <bits/stdc++.h>

using namespace std;

// int hash
struct custom_hash{
    size_t operator()(int x) const{
        x = ((x >> 16) ^ x * 0x45d9f3b);
        x = ((x >> 16) ^ x * 0x45d9f3b);
        x = (x >> 16) ^ x;
        return x;
    }
};

//long long hash
struct custom_hash {
    size_t operator()(long long x) const {
        x = ((x >> 32) ^ x) * 0x45d9f3b97c35c3b1LL;
        x = ((x >> 32) ^ x) * 0x45d9f3b97c35c3b1LL;
        x = (x >> 32) ^ x;
        return x;
    }
};


//string hash
//polynomial hash
struct custom_hash {
    size_t operator()(const string& s) const {
        size_t hash = 0;
        for (char c : s)
            hash = hash * 31 + c;
        return hash;
    }
};

//quick hash
struct custom_hash {
    size_t operator()(const pair<int,int>& p) const {
        size_t h1 = p.first, h2 = p.second;
        // mix h2 into h1 with bit rotation to avoid symmetry
        return h1 ^ (h2 * 0x9e3779b9 + 0x6b3 + (h1 << 6) + (h1 >> 2));
    }
};