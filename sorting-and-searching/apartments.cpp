#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> desired_sizes(n);
    vector<int> sizes(m);

    for(int i = 0; i < n; i ++) cin >> desired_sizes[i];

    for(int i = 0; i < m; i ++) cin >> sizes[i];

    sort(desired_sizes.begin(), desired_sizes.end());

    sort(sizes.begin(), sizes.end());

    int p1 = 0, p2 = 0, total = 0;

    while(p1 < desired_sizes.size() && p2 < sizes.size()){

        if(sizes[p2] - k <= desired_sizes[p1] && desired_sizes[p1] <= sizes[p2] + k){
            total++;
            p1++;
            p2++;
        }else if(desired_sizes[p1] < sizes[p2]){
            p1++;
        } else{
            p2++;
        }

    }

    cout << total;

    return 0;

}