#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long total = 0;

    long long x;
    long long prev = 0;

    for(long long i = 0; i < n; i++){
        cin >> x;
        if(prev > x){
            total += (prev - x);
        }else{
            prev = x;
        }
    }

    cout << total;

    return 0;
}