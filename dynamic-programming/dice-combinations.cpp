#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long first = 1, second = 2, third = 4, fourth = 8, fifth = 16, sixth = 32;

    int n;
    cin >> n;
    long long combinations;

    if(n < 7){
        cout << pow(2, n - 1);
    } else{
        for(int i = 0; i < n - 6; i++){
            combinations = (first + second + third + fourth + fifth + sixth) % (long long)(pow(10, 9) + 7);
            first = second;
            second = third;
            third = fourth;
            fourth = fifth;
            fifth = sixth;
            sixth = combinations;
        }
        
        cout << combinations;
    }

    return 0;


}