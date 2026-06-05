#include <bits/stdc++.h>

using namespace std;


vector<int> minimum;

int solve(int n){

    if(n < 10){ // base case, n < 10, one step
        minimum[n] = 1;
        return 1;
    }

    int x = n;
    int best = INT_MAX;
    while(x > 0){ // tries each digit
        int d = x % 10;

        if(d == 0){
            x /= 10;
            continue;
        } //subtracting 0 doesn't do anything

        if(minimum[n - d] != -1){ //if memorized value exists, use that
            best = min(best, minimum[n - d]);
        } else{
            best = min(best, solve(n - d));
        }
        
        x /= 10;
    }

    minimum[n] = best + 1; //dont forget extra operation
    return best + 1;

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    minimum.assign(n + 1, -1);

    cout << solve(n);

    return 0;

}