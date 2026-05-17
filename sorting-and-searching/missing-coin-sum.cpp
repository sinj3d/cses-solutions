#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> values(n);

    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    sort(all(values));

    ll sum = 0;

    for(int i = 0; i < n; i++){
        if(values[i] > sum + 1){
            cout << sum + 1;
            return 0;
        }
        sum += values[i];
    }

    cout << sum + 1;
    return 0;





}