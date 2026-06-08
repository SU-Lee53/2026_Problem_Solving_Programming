// 파티
// http://210.93.60.51/problem/0163
// Description
//
// N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
//
// 어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다.
// 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti≤ 100)의 시간을 소비한다.
//
// 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다.
// 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
//
// 이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다.
// N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.
//
//
// Input
//
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다.
//
// 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.
// 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.
//
// 모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.
//
//
// Output
//
// 첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Dijikstra(int start, const vector<vector<pair<int, int>>>& g)
{
    vector<int> distance(g.size(), numeric_limits<int>::max());
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (distance[now] < dist) continue;

        for (auto[adj, weight] : g[now]) {
            int cost = dist + weight;
            if (cost < distance[adj]) {
                distance[adj] = cost;
                pq.emplace(cost, adj);
            }
        }
    }

    return distance;
}

int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N+1);
    vector<vector<pair<int, int>>> inv_graph(N+1);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].emplace_back(to, weight);
        inv_graph[to].emplace_back(from, weight);
    }


    auto dist_to_X = Dijikstra(X, inv_graph);    // 모든 마을에서 X 까지의 최단 거리
    auto dist_from_X = Dijikstra(X, graph);    // X에서 모든 마을까지의 최단 거리

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, dist_from_X[i] + dist_to_X[i]);
    }

    cout << ans;
}


