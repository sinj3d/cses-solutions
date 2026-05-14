#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    for(int i = 0; i < t; i ++){
        int n, a, b;

        cin >> n;
        cin >> a;
        cin >> b;

        if((a+b <= n) && ((a == 0) == (b == 0))){

            cout << "YES\n";
            for(int c = n; c > 0; c--){
                cout << c << " ";
            }

            cout << "\n";

            for(int c = n; c > (a + b); c--){
                cout << c << " ";
            }

            for(int c = (a + b); c > 0; c--){
                if(c - b <= 0){
                    cout << a + c << " ";
                } else{
                    cout << c - b << " ";
                }
            }

            cout << "\n";

        }else{

            cout << "NO\n";
            
        }
        
    }

    return 0;

}