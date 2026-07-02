#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;

    vector<array<int, 3>> projects(n);

    for(int i = 0; i < n; i++){
        int a, b, p;
        cin >> a >> b >> p;
        array<int, 3> project = {a, b, p};
        projects[i] = project;
    }

    sort(projects.begin(), projects.end(), [](const auto& a, const auto& b){
        if(a[1] != b[1]){
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    });

    const int END = projects.back()[1];

    vector<long long> dp(END + 1);

    int current = 0;
    for(int i = 1; i <= END; i++){
        while(current < n && projects[current][1] < i){
            current++;
        }

        int options = current;
        long long best = dp[i - 1];
        while(options < n && projects[options][1] == i){
            best = max(best, projects[options][2] + dp[projects[options][0] - 1]);
            options++;
        }

        dp[i] = best;

    }

    cout << dp[END];



    return 0;
}