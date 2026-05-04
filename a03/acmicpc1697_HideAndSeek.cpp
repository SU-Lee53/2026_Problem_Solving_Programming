#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> Next(int x) {
    return { x - 1, x + 1, x * 2 };
}

int BFS(int start, int target)
{
    if (start == target) return 0;

    unordered_set<int> visited;
    queue<pair<int, int>> q;
    for (auto next : Next(start)) {
        if (visited.emplace(next).second == true) {
            q.emplace(next, 1);
        }
    }

    int time = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        auto curPos = cur.first;
        auto curTime = cur.second;

        if (target == curPos) return curTime;

        for (auto& next : Next(curPos)) {
            if (next < 0 || next > 100000) continue;
            if (visited.emplace(next).second == true) {
                q.emplace(next, curTime + 1);
            }
        }
    }

    return -1;
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << BFS(N, K);
}