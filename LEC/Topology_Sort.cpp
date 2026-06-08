
// TopologySort

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

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> Prerequisite(const vector<vector<int>>& graph, vector<int>& indegree, int vertices)
{
    vector<int> result;
    queue<int> q;
    for (int i = 1; i < vertices+1; ++i) {
        if (indegree[i] == 0) {
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.emplace_back(now);
        for (int n : graph[now]) {
            indegree[n] -= 1;
            if (indegree[n] == 0) {
                q.emplace(n);
            }
        }
    }

    return result;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> indegree(v+1, 0);
    vector<vector<int>> graph(v+1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        indegree[b] += 1;
    }

    auto res = Prerequisite(graph, indegree, v);
    for (int n : res) {
        cout << n << " ";
    }

}