#include<bits/stdc++.h>

using namespace std;

long long findLast(const map<int, long long>& dp, long long key){
    return (--dp.lower_bound(key))->second;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<array<long long, 3>> projects(n);
    map<int, long long> dp;

    for(int i = 0; i < n; i++){
        long long a, b, p;
        cin >> a >> b >> p;
        array<long long, 3> project = {a, b, p};
        projects[i] = project;
    }

    dp[0] = 0;

    sort(projects.begin(), projects.end(), [](const auto& a, const auto& b){
        if(a[1] != b[1]){
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    });

    for(auto option : projects){
        dp[option[1]] = max({findLast(dp, option[1]), findLast(dp, option[0]) + option[2], dp[option[1]]});
        
    }

    cout << dp[projects.back()[1]];



    return 0;
}