#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;


    map<int, int> seen; //of the form {value, index}

    if(x == 1){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i = 1; i < n + 1; i++){
        int a;
        cin >> a;
        if(seen.count(x - a)){
            cout << seen[x - a] << " " << i; // zero indexed to one indexed
            return 0;
        }
        seen[a] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}