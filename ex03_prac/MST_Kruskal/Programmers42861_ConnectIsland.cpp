// 섬 연결하기
// https://school.programmers.co.kr/learn/courses/30/lessons/42861
// 제출 내역
// 문제 설명
// n개의 섬 사이에 다리를 건설하는 비용(costs)이 주어질 때,
// 최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용을 return 하도록 solution을 완성하세요.
//
// 다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다.
// 예를 들어 A 섬과 B 섬 사이에 다리가 있고, B 섬과 C 섬 사이에 다리가 있으면 A 섬과 C 섬은 서로 통행 가능합니다.
//
// 제한사항
//
// 섬의 개수 n은 1 이상 100 이하입니다.
// costs의 길이는 ((n-1) * n) / 2이하입니다.
// 임의의 i에 대해, costs[i][0] 와 costs[i] [1]에는 다리가 연결되는 두 섬의 번호가 들어있고,
// costs[i] [2]에는 이 두 섬을 연결하는 다리를 건설할 때 드는 비용입니다.
//
// 같은 연결은 두 번 주어지지 않습니다. 또한 순서가 바뀌더라도 같은 연결로 봅니다.
// 즉 0과 1 사이를 연결하는 비용이 주어졌을 때, 1과 0의 비용이 주어지지 않습니다.
//
// 모든 섬 사이의 다리 건설 비용이 주어지지 않습니다. 이 경우, 두 섬 사이의 건설이 불가능한 것으로 봅니다.
// 연결할 수 없는 섬은 주어지지 않습니다.

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int FindParent(vector<int>& parent, int x)
{
    if (parent[x] != x)
        parent[x] = FindParent(parent, parent[x]);

    return parent[x];
}

void UnionParent(vector<int>& parent, int& a, int& b)
{
    a = FindParent(parent, a);
    b = FindParent(parent, b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int solution(int n, vector<vector<int>> costs)
{
    // Kruskal MST의 방법
    // 1. 각 노드의 Parent가 누구인지 저장하는 테이블을 준비
    // 이때 자기 자신을 부모로 초기화함
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    // 2. 간선의 정보를 저장. 여기서는 costs 로 입력이 들어오므로 생략

    // 본격 Kruskal 의 시작
    // 3. 비용을 기준으로 하여 간선을 정렬함
    sort(costs.begin(), costs.end(), [](const auto& lhs, const auto& rhs) {
       return lhs[2] < rhs[2];
    });

    // 4. 비용이 적은 간선을 하나씩 꺼내서 Cycle을 확인하고 없다면 MST에 포함시키고 union
    int result = 0; // MST 비용의 합
    for (const auto& v : costs) {
        int a = v[0];
        int b = v[1];
        int cost = v[2];

        // 두 노드의 부모가 같으면 Cycle
        if (FindParent(parent, a) != FindParent(parent, b)) {
            UnionParent(parent, a, b);
            result += cost;
        }
    }

    return result;
}

#include <iostream>

int main()
{
    cout << solution(
      4,
      {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}
    );
}



