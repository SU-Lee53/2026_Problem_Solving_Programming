// Dijikstra

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 6 11
 1 2 2
 1 3 5
 1 4 1
 2 4 2
 2 3 3
 3 2 3
 3 6 5
 4 3 3
 4 5 1
 5 3 1
 5 6 2


*/

void dijikstra(const vector<vector<pair<int, int>>> graph, vector<int>& distance, int start)
{
    priority_queue<pair<int, int>> q;
    distance[start] = 0;

    q.emplace(0, start);
    while (!q.empty()) {
        int dist = -q.top().first;
        int now = q.top().second;
        q.pop();

        if (distance[now] < dist) {
            continue;
        }

        for (auto [a, w] : graph[now]) {
            int cost = dist + w;
            if (cost < distance[a]) {
                distance[a] = cost;
                q.emplace(-cost, a);
            }
        }
    }
}


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].emplace_back(b, d);
    }

    vector<int> dist(N+1, std::numeric_limits<int>::max());
    dist[1] = 0;
    dijikstra(graph, dist, 1);

    for (int n : dist) {
        cout << n << ' ';
    }


}
