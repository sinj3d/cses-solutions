#include <bits/stdc++.h>

using namespace std;

void solve_n(int n, int start, int end, int auxiliary);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << pow(2,n) -1 << "\n";

    solve_n(n, 1, 3, 2);

    return 0;

}

void solve_n(int n, int start, int end, int auxiliary){

    if(n == 1){
        cout << start << " " << end << "\n";
    }
    else{
        solve_n(n-1, start, auxiliary, end);
        cout << start << " " << end << "\n";
        solve_n(n-1, auxiliary, end, start);
        return;
    }

}