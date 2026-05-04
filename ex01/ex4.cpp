#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;

vector<pair<int, int>> dir{
    {1, 0}, {1,1}, {0, 1}, {-1, 1},
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
};

int DFS_stack(int r, int c, int R, int C)
{
    stack<pair<int, int>> s;
    s.emplace(r,c);
    int size = 0;

    while (!s.empty()) {
        auto p = s.top();
        s.pop();

        auto [cr, cc] = p;
        if (!visited[cr][cc]) {

            visited[cr][cc] = true;
            size++;

            for (auto[dr, dc] : dir) {
                int nr = cr + dr, nc = cc + dc;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (graph[nr][nc] != '.') continue;
                if (visited[nr][nc]) continue;

                s.emplace(nr, nc);
            }
        }
    }

    return size;

}



int main()
{
    int R, C;
    cin >> R >> C;

    graph.resize(R, vector<char>(C, '.'));
    visited.resize(R, vector<bool>(C, false));

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> graph[r][c];
        }
    }

    int K; cin >> K;

    int nCnt = 0;
    int nMax = -INT_MAX;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (!visited[r][c] && graph[r][c] == '.') {
                int res = DFS_stack(r,c, R, C);

                if (res > K) {
                    nCnt++;
                    nMax = std::max(nMax, res);
                }
            }
        }
    }

    cout << nCnt << ' ' << nMax;
}