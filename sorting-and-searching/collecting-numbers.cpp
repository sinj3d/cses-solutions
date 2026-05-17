#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> values;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        values[x] = i;
    }

    int rounds = 1;
    for(int i = 1; i < n; i++){
        if(values[i] > values[i + 1]){
            rounds++;
        }
    }

    cout << rounds;
    return 0;

}