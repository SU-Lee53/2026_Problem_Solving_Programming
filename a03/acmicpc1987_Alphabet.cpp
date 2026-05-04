// 문제
// 세로
// $R$칸, 가로
// $C$칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (
// $1$행
// $1$열) 에는 말이 놓여 있다.
//
// 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데,
// 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.
//
// 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
//
// 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
//
// 입력
// 첫째 줄에
// $R$과
// $C$가 빈칸을 사이에 두고 주어진다. (
// $1 ≤ R,C ≤ 20$) 둘째 줄부터
// $R$개의 줄에 걸쳐서 보드에 적혀 있는
// $C$개의 대문자 알파벳들이 빈칸 없이 주어진다.
//
// 출력
// 첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> dir{
{1, 0}, {-1, 0},
{0, 1}, {0, -1}
};


int nMaxDistance = 0;

void DFS(int r, int c, int distance, const vector<vector<int>>& graph, vector<bool>& visited)
{
    if (distance == 26) {
        nMaxDistance = distance;
        return;
    }

    nMaxDistance = max(nMaxDistance, distance);
    for (auto& [dr, dc] : dir) {
        int NR = r + dr, NC = c + dc;
        if (NR < 0 || NR > graph.size() - 1 || NC < 0 || NC > graph[0].size() - 1) continue;
        if (visited[graph[NR][NC]]) continue;
        visited[graph[NR][NC]] = true;
        DFS(NR, NC, distance + 1, graph, visited);
        visited[graph[NR][NC]] = false;
    }
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> v(R, vector<int>(C, '0'));

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char in;
            cin >> in;
            v[r][c] = in - 65;
        }
    }

    vector<bool> visited(26, false);
    visited[v[0][0]] = true;
    DFS(0, 0, 1, v, visited);

    cout << nMaxDistance;

}
