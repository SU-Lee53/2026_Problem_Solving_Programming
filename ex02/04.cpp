

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> b;
vector<pair<int, int>> dir{
{1,0}, {0,1}, {-1, 0}, {0, -1}
};


int main()
{
    int R, C; cin >> R >>C;
    b.resize(R, vector<int>(C, 0));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> b[r][c];
        }
    }

    int turn; cin >> turn;

    vector<vector<vector<int>>> dp(turn+1, vector<vector<int>>(R, vector<int>(C, 0)));

    // dp[t][i][j] = max(dp[t-1][i-1][j], dp[t-1][i+1][j], dp[t-1][i][j-1], dp[t-1][i][j+1]) + board[i][j]

    for (int t = 1; t <= turn; ++t) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                for (auto [dr, dc] : dir) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    dp[t][r][c] = max(dp[t][r][c], dp[t-1][nr][nc] + b[r][c]);
                }
            }
        }
    }

    int res = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            res = max(dp[turn][r][c], res);
        }
    }

    cout << res;

}