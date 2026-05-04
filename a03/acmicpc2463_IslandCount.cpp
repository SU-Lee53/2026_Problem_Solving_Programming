// 문제
// 정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.
//
//
//
// 한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.
//
// 두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
//
// 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.
//
// 둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
//
// 입력의 마지막 줄에는 0이 두 개 주어진다.
//
// 출력
// 각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> dir = {
    {-1, 0}, {1, 0},
    {-1, 1}, {1, 1},
    {0, -1}, {0, 1},
    {-1, -1}, {1, -1}
};

void DFS(const pair<int, int>& start, const vector<vector<int>>& graph, vector<vector<bool>>& visited)
{
    auto [c,r] = start;

    if (!visited[c][r]) {
        visited[c][r] = true;

        for (auto [x, y] : dir) {
            int NR = r + x, NC = c + y;
            if (NR < 0 || NC < 0 || NR >= graph[0].size() || NC >= graph.size()) continue;
            if (graph[NC][NR] != 1) continue;

            DFS({NC, NR}, graph, visited);
        }
    }
}


int main()
{
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == h && w == 0) break;

        vector<vector<int>> graph(h, vector<int>(w, 0));
        for (int c = 0; c < h; ++c) {
            for (int r = 0; r < w; ++r) {
                int n;
                cin >> n;
                graph[c][r] = n;
            }
        }

        vector<vector<bool>> visited(h, vector<bool>(w, false));

        int answer = 0;
        for (int c = 0; c < h; ++c) {
            for (int r = 0; r < w; ++r) {
                if (!visited[c][r] && graph[c][r] == 1) {
                    DFS({c,r}, graph, visited);
                    answer++;
                }
            }
        }

        std::cout << answer << std::endl;
    }

    return 0;

}
