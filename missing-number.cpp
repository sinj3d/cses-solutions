#include <bits/stdc++.h>
using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
//     vector<int> arr(n-1);

//     for(int i  = 0; i < n-1; i++){
//         cin >> arr[i];
//     }

//     set<int> intSet;
//     for(int i  = 0; i < n-1; i++){
//         intSet.insert(arr[i]);
//     }

//     for(int i = 1; i < n+1; i++){
//         if(intSet.find(i) == intSet.end()){
//             cout << i;
//         }
//     }

//     return 0;
// }

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long expected_sum = n*(n+1)/2;
    long long current_sum = 0;
    long long num;
    for(int i = 0; i< n - 1; i++){
        cin >> num;
        current_sum += num;
    }

    cout << expected_sum - current_sum;

    return 0;
}