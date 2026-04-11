#include <bits/stdc++.h>

using namespace std;

string toBinary(int n, int numBits) {
    string result = "";
    
    for (int i = numBits - 1; i >= 0; i--) {
        // Shift bit 'i' to the right and check if it's 1
        int bit = (n >> i) & 1;
        result += (bit == 1 ? '1' : '0');
    }
    
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memory;
    memory.reserve(1 << n);


    memory.push_back(0); // initialize the list with the greycode for n = 1
    memory.push_back(1);
    cout << toBinary(0, n);
    cout << toBinary(1, n);


    for(int i = 2; i <= n; i++){ // we use previous greycodes to build. To keep the hamming distance at 1, we walk backwards through memory
        int lead1 = 1 << (i-1);
        for(int j = 1 << (i-1) - 1; j >= 0; j--){
            cout << toBinary(lead1 + memory[j], n) << '\n';
            memory.push_back(lead1 + memory[j]);
        }
    }
    
    return 0;

}

// There is a more optimal formula that doesn't require memorization. I didn't find it, but it is:

// int total_combinations = 1 << n; // 2^n

//     for (int i = 0; i < total_combinations; i++) {
//         // Calculate the i-th Gray code directly
//         int gray = i ^ (i >> 1);
        
//         // Print the binary representation directly, avoiding strings
//         for (int j = n - 1; j >= 0; j--) {
//             cout << ((gray >> j) & 1);
//         }
//         cout << '\n';
//     }

// This works because the algorithm is a bijection on the range (1, 2**n), and XOR guarantees the hamming distance is 1