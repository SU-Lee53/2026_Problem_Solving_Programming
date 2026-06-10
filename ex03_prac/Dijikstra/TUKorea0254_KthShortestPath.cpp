// K번째 최단경로 찾기
// http://210.93.60.51/problem/0254
// Description
//
// 봄캠프를 마친 김진영 조교는 여러 도시를 돌며 여행을 다닐 계획이다. 그런데 김 조교는, '느림의 미학'을 중요시하는 사람이라 항상 최단경로로만 이동하는 것은 별로 좋아하지 않는다. 하지만 너무 시간이 오래 걸리는 경로도 그리 매력적인 것만은 아니어서, 적당한 타협안인 'k번째 최단경로' 를 구하길 원한다. 그를 돕기 위한 프로그램을 작성해 보자.
//
//
// Input
//
// 첫째 줄에n,m,k가 주어진다. (1 ≤ n ≤ 1,000,0 ≤ m ≤ 250,000,1 ≤ k ≤ 100,mk ≤ 3,000,000)
//
// n과m은 각각 김 조교가 여행을 고려하고 있는 도시들의 개수와, 도시 간에 존재하는 도로의 수이다.
//
// 이어지는m개의 줄에는 각각 도로의 정보를 제공하는 세 개의 정수a,b,c가 포함되어 있다. 이것은a번 도시에서b번 도시로 갈 때는c의 시간이 걸린다는 의미이다. (1 ≤ a, b ≤ n,1 ≤ c ≤ 1,000)
//
// 도시의 번호는1번부터n번까지 연속하여 붙어 있으며,1번 도시는 시작도시이다. 두 도로의 시작점과 도착점이 모두 같은 경우는 없다.
//
//
// Output
//
// n개의 줄을 출력한다.i번째 줄에1번 도시에서i번 도시로 가는k번째 최단경로의 소요시간을 출력한다.
//
// 경로의 소요시간은 경로 위에 있는 도로들을 따라 이동하는데 필요한 시간들의 합이다.i번 도시에서i번 도시로 가는 최단경로는0이지만, 일반적인k번째 최단경로는0이 아닐 수 있음에 유의한다. 또,k번째 최단경로가 존재하지 않으면 -1을 출력한다. 최단경로에 같은 정점이 여러 번 포함되어도 된다.


#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

using GraphType = vector<vector<pair<int, int>>>;

vector<priority_queue<int>> nth_path(const GraphType& g, int start, int k)
{
    // dist[v] -> v 까지 가는 거리 후보. Max Heap 으로 k 개만 보관 -> 최종 top() 이 k번째 최단거리
    vector<priority_queue<int>> distances(g.size());
    distances[1].push(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [dist, cur] = pq.top();
        pq.pop();

        for (auto& [next, weight] : g[cur]) {
            int cost = dist + weight;
            if (distances[next].size() < k) { // 아직 후보가 k개만큼 쌓이지 않음
                distances[next].push(cost);	// 후보로 집어넣음
                pq.emplace(cost, next);		// pq 에 push
            }
            else if (distances[next].top() > cost) { // 후보 꽉참 + 이전까지 찾은 최장거리보다 지금찾은게 더 빠름
                distances[next].pop();	// 가장 먼 거리 제거
                distances[next].push(cost);
                pq.emplace(cost, next);
            }
        }
    }

    return distances;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    GraphType roads(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a].emplace_back(b, c);
    }

    auto d = nth_path(roads, 1, k);
    for (int i = 1; i <= n; ++i) {
        if (d[i].size() < k) cout << -1;
        else cout << d[i].top();
        cout << '\n';
    }

}