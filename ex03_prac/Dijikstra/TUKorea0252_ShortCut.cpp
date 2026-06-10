// 지름길
// http://210.93.60.51/problem/0252
// Description
//
// 매일 아침, 세준이는 학교에 가기 위해서 차를 타고 D킬로미터 길이의 고속도로를 지난다. 이 고속도로는 심각하게 커브가 많아서 정말 운전하기도 힘들다. 어느 날, 세준이는 이 고속도로에 지름길이 존재한다는 것을 알게 되었다. 모든 지름길은 일방통행이고, 고속도로를 역주행할 수는 없다.
//
// 세준이가 운전해야 하는 거리의 최솟값을 출력하시오.
//
//
// Input
//
// 첫째 줄에 지름길의 개수 N과 고속도로의 길이 D가 주어진다. N은 12 이하인 양의 정수이고, D는 10,000보다 작거나 같은 자연수이다. 다음 N개의 줄에 지름길의 시작 위치, 도착 위치, 지름길의 길이가 주어진다. 모든 위치와 길이는 10,000보다 작거나 같은 음이 아닌 정수이다. 지름길의 시작 위치는 도착 위치보다 작다.
//
//
// Output
//
// 세준이가 운전해야하는 거리의 최솟값을 출력하시오.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <limits>

using namespace std;
using GraphType = unordered_map<int, vector<pair<int, int>>>;

unordered_map<int, int> Dijikstra(GraphType& g, int start)
{
    unordered_map<int, int> distance;
    for (auto [pos_from, roads] : g) {
        distance[pos_from] = numeric_limits<int>::max();
        for (const auto& [pos_to, cost] : roads) {
            distance[pos_to] = numeric_limits<int>::max();
        }
    }
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [dist, now] = pq.top();
        pq.pop();

        if (distance[now] < dist) continue;
        for (const auto& [next, weight] : g[now]) {
            int cost = dist + weight;
            if (distance[next] > cost) {
                distance[next] = cost;
                pq.emplace(cost, next);
            }
        }
    }

    return distance;
}

int main()
{
    int N, D;
    cin >> N >> D;

    int id = 0;
    GraphType g;

    // 0 ~ 발견된 위치 ~ D 까지 모든 도로의 완전한 연결이 필요함 (지름길 제외)
    set<int> known_position_set;
    known_position_set.insert(0);
    known_position_set.insert(D);
    g[0] = {};
    g[D] = {};

    for (auto i = 0; i < N; ++i) {
        int s, e, c;
        cin >> s >> e >> c;
        g[s].emplace_back(e, c);

        known_position_set.insert(s);
        known_position_set.insert(e);
    }

    vector<int> v{ known_position_set.begin(), known_position_set.end() };
    for (int s = 0; s < v.size() - 1; ++s) {
        for (int e = s + 1; e < v.size(); ++e) {
            g[v[s]].emplace_back(v[e], v[e] - v[s]);
        }
    }

    auto d = Dijikstra(g, 0);
    cout << d[D];
}