#include <bits/stdc++.h>

using namespace std;

void coutrecur(int i, vector<int>& charfreq, int oddIndex){

    if(i == 26){
        if(oddIndex != -1){
            cout << char(oddIndex + 'A');
        }
        return;
    }

    for(int j = 0; j < charfreq[i]/2; j++){
        cout << char(i + 'A');
    }

    coutrecur(i + 1, charfreq, oddIndex);

    for(int j = 0; j < charfreq[i]/2; j++){
        cout << char(i + 'A');
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> charfreq(26, 0);
    string s;

    cin >> s;

    for(char c: s){
        charfreq[c - 'A']++;
    }

    int oddIndex = -1;

    for(int i = 0; i < 26; i++){
        if(charfreq[i] % 2 != 0){
            if(oddIndex != -1){
                cout << "NO SOLUTION\n";
                return 0;
            }
            oddIndex = i;
        }
    }

    coutrecur(0, charfreq, oddIndex);
    cout << "\n";

    return 0;
}

