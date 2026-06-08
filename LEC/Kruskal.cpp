
// Kruskal algorithm

/*
7 9
1 2 29
1 5 75
2 6 34
5 6 53
2 3 55
3 4 7
4 6 23
6 7 25
4 7 13
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int FindParent(vector<int>& parent, int x)
{
    if (parent[x] != x)
        parent[x] = FindParent(parent, parent[x]);

    return x;
}

void UnionParent(vector<int>& parent, int& a, int& b)
{
    a = FindParent(parent, a);
    b = FindParent(parent, b);

    if (a < b) {
        parent[b] = a;
    }else {
        parent[a] = b;
    }
}

int main()
{
    int v, e; cin >> v >> e;    // v : 노드수, e : 간선수
    vector<int> parentTable(v+1);
    iota(parentTable.begin(), parentTable.end(), 0);

    vector<vector<int>> edges;
    for (int i = 0; i < e; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.emplace_back(initializer_list<int>{cost, a, b});
    }

    // Kruskal algorithm
    // 1. 비용을 기준으로 간선 정렬
    sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
        return lhs[0] < rhs[0];
    });

    // 2. 비용이 작은 간선을 꺼내서 사이클이 없다면 MST에 포함시키고 union
    int result = 0; // MST 비용의 합
    for (const auto& v : edges) {
        int cost = v[0];
        int a = v[1];
        int b = v[2];
        if (FindParent(parentTable, a) != FindParent(parentTable, b)) { // 사이클 존재
            UnionParent(parentTable, a, b);
            result += cost;
        }
    }

    cout << result;
}

