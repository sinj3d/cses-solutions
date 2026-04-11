#include <bits/stdc++.h>

using namespace std;

vector<string> search(string prev, vector<int> charFreq, int target);
int factorial(int n);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> charFreq(26,0);

    string line;
    getline(cin, line);

    for(char c: line){
        charFreq[c - 'a']++;
    }

    int total = factorial(size(line));

    for(int i : charFreq){
        if(i == 0){
            continue;
        } else{
            total /= factorial(i);
        }
    }

    cout << total << "\n";

    string str;
    vector<string> result = search(str, charFreq, size(line));

    for(string s: result){
        cout << s << "\n";
    }

    return 0;
}

vector<string> search(string prev, vector<int> charFreq, int target){
    vector<string> result;
    if(size(prev) == target){
        return {prev};
    }else{
        for(int i = 0; i < size(charFreq); i++){
            if(charFreq[i] != 0){
                charFreq[i]--;
                vector<string> subresult = search(prev + (char)(i + 'a'), charFreq, target);
                result.insert(result.end(), subresult.begin(), subresult.end());
                charFreq[i]++;
            }
        }
    }
    return result;
}

int factorial(int n){

    int total = 1;

    for(int i = 1; i <= n; i++){
        total *= i;
    }

    return total;
}

// Alternative solution with next_permutation
/*
int main(){

    string line;
    getline(cin, line);

    vector<int> charFreq(26,0);

    for(char c: line){
        charFreq[c - 'a']++;
    }

    int total = factorial(size(line));

    for(int i : charFreq){
        if(i == 0){
            continue;
        } else{
            total /= factorial(i);
        }
    }

    cout << total << "\n";

    sort(line.begin(), line.end());

    do{
        cout << line << "\n";
    } while(next_permutation(line.begin(), line.end()));
}
*/