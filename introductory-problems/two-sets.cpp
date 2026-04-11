#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long total = 1LL*n*(n+1)/2;

    if(total % 2){ // if the sum of the numbers up to n are even, then it is possible
        cout << "NO" << "\n";

    }else {
        cout << "YES" << "\n";
        // greedy
        long long sum = 0;
        int largest_num = n;
        vector<int> set1;
        vector<int> set2;

        while(sum < total/2){
            if(sum + largest_num > total/2){
                set2.push_back(largest_num);
            }else{
                sum += largest_num;
                set1.push_back(largest_num);
            }
            largest_num--;
        }

        for(int i = largest_num; i > 0; i--){
            set2.push_back(i);
        }

        cout << set1.size() << '\n';

        for(int i: set1){
            cout << i << ' ';
        }
        cout << '\n';

        cout << set2.size() << '\n';

        for(int i: set2){
            cout << i << ' ';
        }
        
    }

    return 0;

}