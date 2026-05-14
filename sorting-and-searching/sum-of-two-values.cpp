#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;


    unordered_map<int, int> seen; //of the form {value, index}

    for(int i = 1; i < n + 1; i++){
        int a;
        cin >> a;

        if(!seen.count(x - a)){
            seen[a] = i;
        }else{
            cout << seen[x - a] << " " << i; // zero indexed to one indexed
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}