#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    long long a;
    long long b;
    for(int i = 0; i < t; i++){
        cin >> a;
        cin >> b;
        if(a > 2*b || b > 2*a || (a+b) % 3 != 0){
            cout << "NO\n"; 
            continue;
        }
        cout << "YES\n";
        
    }

    return 0;
}