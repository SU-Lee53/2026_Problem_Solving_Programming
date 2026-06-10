// 공주 구하기
// http://210.93.60.51/problem/0055
// Description
//
// 이 게임은M × N직사각형 격자 형태의방들 중하나에 공주님이 갖혀 있습니다.
//
// 왕자는 공주를 구하러 가고 있습니다.
//
// 왕자는 (1,1)이라고 표시된 왼쪽 상단 방에서 시작합니다.각 방에는 경비원들이 있습니다.
//
// 왕자가 자신이있는 방에있는 모든 경비원들을 해치우는 시간은 경비원 숫자에 비례합니다.
//
// 각 방에 있는 경비원 숫자는 방마다 다르며, 1명의 경비원을 해치우는데 걸리는 시간은 1초입니다.
//
// 방에있는 모든 경비원을 해치운 후에는 상, 하, 좌, 우 인접한 방중에서 하나로 이동할 수 있습니다.
//
// 왕자가 오는 것을 알고있는 마녀는T초후에 폭발하는 시한 폭탄을 설정했습니다.
//
// 공주의 위치, 폭탄이 터질 때까지 남은 시간, MxN 격자의 각 방에 있는 경비원 숫자가 주어집니다.
//
// 당신이 할일은 왕자가 최단시간에 공주에게 도달하여 T초가 만료되기 전에 폭탄을 해체하면 남는 최대 여유 시간을 출력합니다.
//
// 만약 시한 폭탄이 폭발하기 전에 도달하지 못하는 경우는 없습니다.
//
// 예를 들어, 4x3 직사각형 방의 경비원 숫자가 다음과 같이 설명된다고 가정합니다.
//
// 2 3 2
// 2 5 1
// 5 3 1
// 3 1 1
//
//
// 위치(i, j)의 숫자는 방(i, j)의 경비원 숫자를 나타냅니다. 공주가 (4,2) 위치의 방에 있다고 가정합니다.
//
// T=15라면 왕자는 다음과 같이 4 초의 여유를 가지고 공주에게 갈 수있다.
//
// (1,1)에서 시작하여 오른쪽으로 (1,2)로 이동 한 다음 (1,3)으로 이동하고 (4,3)까지 쭉 아래로 내려온 다음 (4,2)로 이동합니다. 이 작업에는 11 초가 걸립니다(공주가 수감 된 방에서도 경비원들을 제압해야합니다). 어떤 경로로든 4 초 이상 여유 시간을 가지고 공주에게 다가 갈 수 없습니다.
//
// Input
//
// 첫 번째 줄에는직사각형 격자의 행과 열 수를 나타내는두 개의 정수M과N이있습니다.
//
// 2,3,…,M+1 행에는N 개의양의 정수가 포함됩니다.
//
// i+1번째 줄의j번째정수는 방(i, j)에서 경비원의 수를 나타냅니다.
//
// 입력의 마지막 줄인M+2번째 줄에는 세 개의 정수a,b및T가 포함되어 있습니다. 여기서(a, b)는 공주가 있는 방의 위치이고T는 폭탄이 터지기 전까지의 시간입니다.
//
// 1 ≤N, K≤ 70
//
//
//
//
// Output
//
// 폭탄이 터지기 전에 왕자가 공주를 구출 할 때 남은 최대 시간을 나타내는 단일 정수

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using GraphType = vector<vector<int>>;
vector<pair<int, int>> dir = {
    {1, 0}, {-1, 0},
    {0, 1}, {0, -1}
};

vector<vector<int>> Dijikstra(GraphType& g, int sr, int sc)
{
    vector<vector<int>> visited(g.size(), vector<int>(g[0].size(), 0));
    visited[sr][sc] = 1;

    vector<vector<int>> time(g.size(), vector<int>(g[0].size(), numeric_limits<int>::max()));
    time[sr][sc] = g[sr][sc];

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({ g[sr][sc], {sr, sc} });

    while (!pq.empty()) {
        auto [spent, cur_pos] = pq.top();
        auto [cr, cc] = cur_pos;
        pq.pop();

        if (time[cr][cc] < spent) continue;

        for (auto [dr, dc] : dir) {
            int nr = cr + dr;
            int nc = cc + dc;
            if (nr < 1 || nr >= g.size()) continue;
            if (nc < 1 || nc >= g[0].size()) continue;

            int next_spent = spent + g[nr][nc];
            if (time[nr][nc] > next_spent) {
                time[nr][nc] = next_spent;
                pq.push({ next_spent, { nr, nc } });
                visited[nr][nc] = 1;
            }
        }

    }

    return time;
}

int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> map(M+1, vector<int>(N+1, 0));
    for (int r = 1; r <= M; ++r) {
        for (int c = 1; c <= N; ++c) {
            cin >> map[r][c];
        }
    }

    int a, b, T;
    cin >> a >> b >> T;

    auto d = Dijikstra(map, 1, 1);
    cout << T - d[a][b];
}