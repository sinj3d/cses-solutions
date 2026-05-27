#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map <int, int> last_occurence;

    int best = 0;
    int l = 0;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        if(last_occurence.count(k) && last_occurence[k] >= l){
            l = last_occurence[k] + 1;
        }

        last_occurence[k] = i;

        best = max(i - l + 1, best);

    }

    cout << best;
    return 0;



}