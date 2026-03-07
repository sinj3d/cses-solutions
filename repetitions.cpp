#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input; //unnecessary. Having while(cin >> c) automatically loops through the input
    cin >> input;

    int maxlen = 0;
    int curlen = 0;
    char prev;

    for(char c: input){
        if(c != prev){
            curlen = 0;
            prev = c;
        }
        curlen++;
        maxlen = max(curlen, maxlen);
    }

    cout << maxlen;

    return 0;

}