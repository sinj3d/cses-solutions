#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies[i] = {a, b};
    }



    sort(movies.begin(), movies.end(),  [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });

    int total = 0;
    int curend = 0;

    for(int i = 0; i < n; i++){
        if(movies[i].first >= curend){
            total++;
            curend = movies[i].second;
        }
    }

    cout << total;

    return 0;
}