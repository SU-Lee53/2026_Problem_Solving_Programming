
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkRow[9] = {false,};
bool checkCol[9] = {false,};
bool checkBox[9] = {false,};

bool check(int r, int c, vector<vector<int>> board)
{
    for (int i = 0; i < 9; ++i) {
        checkRow[i] = false;
        checkCol[i] = false;
        checkBox[i] = false;
    }

    // 1. Check Row
    for (int i = 0; i < 9; ++i) {
        if (board[r][i] == 0) continue;
        if (checkRow[board[r][i] -1] == true) return false;
        checkRow[board[r][i] - 1] = true;
    }

    // 2. Check col
    for (int i = 0; i < 9; ++i) {
        if (board[i][c] == 0) continue;
        if (checkCol[board[i][c] -1] == true) return false;
        checkCol[board[i][c] - 1] = true;
    }

    // 3. Check box
    int br = std::floor((float) r / 3.f);
    int bc = std::floor((float) c / 3.f);
    for (int i = br * 3; i < (br + 1) * 3; ++i) {
        for (int j = bc * 3; j < (bc + 1) * 3; ++j) {
            if (board[i][j] == 0) continue;
            if (checkBox[board[i][j] -1] == true) return false;
            checkBox[board[i][j] - 1] = true;

        }
    }

    return true;
}



int main()
{
    int N; cin >> N;

    for (int i = 0; i < N; ++i) {
        vector<vector<int>> board(9, vector<int>(9, 0));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char in; cin >> in;
                while (in == '-' || in == '|' || in == '+') {
                    cin >> in;
                }
                board[r][c] = (in == '.') ? 0 : in - '0';
            }
        }

        bool res;
        for (int r = 0; r < 9; ++r) {
            res = false;
            for (int c = 0; c < 9; ++c) {
                res = check(r, c, board);
                if (res == false) break;

            }
            if (res == false) break;
        }

        if (res) cout << 'Y' << endl;
        else cout << 'N' << endl;

    }

}