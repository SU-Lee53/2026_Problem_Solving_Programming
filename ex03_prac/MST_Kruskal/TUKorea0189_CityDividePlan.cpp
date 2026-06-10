// 도시 분할 계획
// http://210.93.60.51/problem/0189
// Description
//
// 동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다.
// 그러다가 평화로운 마을에 가게 되었는데, 그곳에서는 알 수 없는 일이 벌어지고 있었다.
//
// 마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져 있다.
// 길은 어느 방향으로든지 다닐 수 있는 편리한 길이다.
// 그리고 각 길마다 길을 유지하는데 드는 유지비가 있다.
// 임의의 두 집 사이에 경로가 항상 존재한다.
//
// 마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다.
// 마을이 너무 커서 혼자서는 관리할 수 없기 때문이다.
// 마을을 분할할 때는 각 분리된 마을 안에 집들이 서로 연결되도록 분할해야 한다.
// 각 분리된 마을 안에 있는 임의의 두 집 사이에 경로가 항상 존재해야 한다는 뜻이다.
// 마을에는 집이 하나 이상 있어야 한다.
//
// 그렇게 마을의 이장은 계획을 세우다가 마을 안에 길이 너무 많다는 생각을 하게 되었다.
// 일단 분리된 두 마을 사이에 있는 길들은 필요가 없으므로 없앨 수 있다.
// 그리고 각 분리된 마을 안에서도 임의의 두 집 사이에 경로가 항상 존재하게 하면서 길을 더 없앨 수 있다.
// 마을의 이장은 위 조건을 만족하도록 길들을 모두 없애고 나머지 길의 유지비의 합을 최소로 하고 싶다.
// 이것을 구하는 프로그램을 작성하시오.
//
//
// Input
// 첫째 줄에 집의 개수 N, 길의 개수 M이 주어진다.
// N은 2이상 100,000이하인 정수이고, M은 1이상 1,000,000이하인 정수이다.
// 그 다음 줄부터 M줄에 걸쳐 길의 정보가 A B C 세 개의 정수로 주어지는데
// A번 집과 B번 집을 연결하는 길의 유지비가 C (1 ≤ C ≤ 1,000)라는 뜻이다.
//
// 임의의 두 집 사이에 경로가 항상 존재하는 입력만 주어진다.
//
// Output
// 첫째 줄에 없애고 남은 길 유지비의 합의 최솟값을 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int FindParent(vector<int>& pt, int x)
{
    if (pt[x] != x)
        pt[x] = FindParent(pt, pt[x]);

    return pt[x];
}

void UnionParent(vector<int>& pt, int& a, int& b)
{
    a = FindParent(pt, a);
    b = FindParent(pt, b);

    if (a < b) {
        pt[b] = a;
    }
    else {
        pt[a] = b;
    }
}


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges;
    edges.reserve(M);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.emplace_back(initializer_list<int>{A, B, C});
    }

    sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
       return lhs[2] < rhs[2];
    });

    vector<int> pt(N+1);
    iota(pt.begin(), pt.end(), 0);


    // MST로 일단 모든 집을 다 연결한 다음, 도로 하나만 끊으면 마을 2개가 분리됨
    // 이때 제일 비싼 도로를 끊어야 유지비가 최소화됨
    int total_cost = 0;
    int max_cost = 0;
    for (const auto& v : edges) {
        int a = v[0];
        int b = v[1];
        int cost = v[2];

        if (FindParent(pt, a) != FindParent(pt, b)) {
            UnionParent(pt, a, b);
            total_cost += cost;
            max_cost = max(max_cost, cost);
        }
    }

    cout << total_cost - max_cost;

}




