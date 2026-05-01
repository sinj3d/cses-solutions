#include <bits/stdc++.h>

using namespace std;

vector<string> board(8);

int solve_subboard(int row, int cols, int diag, int anti_diag){

    if(row == 8){
        return 1;
    }

    int total = 0;

    auto is_safe = [&](int r, int i){
        if (board[r][i] != '.') return false;
        if (cols & (1 << i)) return false;
        if (diag & 1 << (7 + (row - i))) return false;
        if (anti_diag & (1 << (row + i))) return false;

        return true;
    };

    for(int i = 0; i < 8; i++){

        if(is_safe(row, i)){

            total += solve_subboard(row + 1,
                (cols | (1 << i)),
                (diag | (1 << (7 + row - i))),
                (anti_diag | (1 << (row + i))));

        }

    }
    return total;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int r = 0; r < 8; r++){
        cin >> board[r];
    }

    cout << solve_subboard(0, 0, 0, 0) << "\n";

    return 0;

}