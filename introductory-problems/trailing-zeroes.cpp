#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int pow5 = log(n)/log(5);
    int zeroes = 0;

    for(int i = 1; i <= pow5; i++){
        zeroes += n/pow(5,i);
    }

    cout << zeroes << '\n';

    return 0;
}