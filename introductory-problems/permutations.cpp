#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n == 1){
        cout << '1';
        return 0;
    }

    if(n < 4){
        cout << "NO SOLUTION\n";
        return 0;
    }

    //algorithm starts at n-1, prints down, skipping one each time until it can't, then loops back to n and prints down
    int i = n-1;
    while(i > 0){
        cout << i << ' ';
        i-=2;
    }

    i = n;
    while(i > 0){
        cout << i << ' ';
        i-=2;
    }

    return 0;
}