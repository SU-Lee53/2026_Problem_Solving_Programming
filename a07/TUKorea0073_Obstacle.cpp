// [2021 본선 H] 장애물
// http://210.93.60.51/problem/0073
// Description
// 정점의 개수 V와 간선의 개수 E (1≤V≤250, 1≤E≤25,000) 로 이루어진 양방향 그래프가 주어진다.
// 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
// 항상 시작 정점은 1이고 목적지는 V이다.
// 모든 간선의 가중치는 1,000,000 이하의 자연수이다.
// 원래 최단 경로의 길이 A를 구한다.
// 그런 후 임의의 간선에 장애물이 떨어져서 가중치가 2배가 되었다고 가정하고 최단 경로 B를 구한다.
// 최종적으로 B-A의 최대값을 구한다.
//
// Input
// 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다.(1≤V≤250, 1≤E≤25,000)
// 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
// 둘째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다.
// 이는 u에서 v로 그리고 v에서 u로 가는 가중치 w인 양방향 간선이 존재한다는 뜻이다.
// u와 v는 서로 다르며 w는1,000,000 이하의 자연수이다.
//
// Output
// 임의의 간선에 가중치를 2배로 했을 때 원래 최단 경로 길이에서 늘어나는 최대값을 출력

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

vector<int64_t> Dijikstra(const vector<vector<int64_t>>& g, int x, vector<int>& previous)
{
    previous.resize(g.size());

    vector<int64_t> dist(g.size(), numeric_limits<int64_t>::max());
    dist[x] = 0;

    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
    pq.emplace(0, x);

    while (!pq.empty()) {
        int64_t cur_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cur_dist) continue;

        for (int i = 0; i < g[now].size(); ++i) {
            if (g[now][i] == -1) continue;  // 연결 X
            int64_t cost = cur_dist + g[now][i];
            if (cost < dist[i]) {
                dist[i] = cost;
                previous[i] = now;
                pq.emplace(cost, i);
            }
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int64_t>> g(V+1, vector<int64_t>(V+1, -1));

    for (int i = 0; i < E; ++i) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }

    vector<int> previous;
    auto dist = Dijikstra(g, 1, previous);

    int64_t original_cost = dist[V];

    int64_t answer = 0;
    int obs_to = V;
    int obs_from = previous[V];
    while (obs_to != 1) {
        g[obs_from][obs_to] *= 2;

        vector<int> temp;
        vector<int64_t> obs_dist = Dijikstra(g, 1, temp);
        int64_t obs_cost = obs_dist[V];
        answer = max(answer, obs_cost - original_cost);

        g[obs_from][obs_to] /= 2;

        obs_to = obs_from;
        obs_from = previous[obs_from];
    }

    cout << answer;
}
