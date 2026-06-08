// 선수과목 (Prerequisite)
// http://210.93.60.51/problem/0190
// Description
//
// 올해 Z대학 컴퓨터공학부에 새로 입학한 민욱이는 학부에 개설된 모든 전공과목을 듣고 졸업하려는 원대한 목표를 세웠다.
// 어떤 과목들은 선수과목이 있어 해당되는 모든 과목을 먼저 이수해야만 해당 과목을 이수할 수 있게 되어 있다.
// 공학인증을 포기할 수 없는 불쌍한 민욱이는 선수과목 조건을 반드시 지켜야만 한다.
// 민욱이는 선수과목 조건을 지킬 경우 각각의 전공과목을 언제 이수할 수 있는지 궁금해졌다.
// 계산을 편리하게 하기 위해 아래와 같이 조건을 간소화하여 계산하기로 하였다.
//
// 한 학기에 들을 수 있는 과목 수에는 제한이 없다.
// 모든 과목은 매 학기 항상 개설된다.
// 모든 과목에 대해 각 과목을 이수하려면 최소 몇 학기가 걸리는지 계산하는 프로그램을 작성하여라.
//
//
// Input
// 첫 번째 줄에 과목의 수 N(1 ≤ N ≤ 1000)과 선수 조건의 수 M(0 ≤ M ≤ 500000)이 주어진다.
// 선수과목 조건은 M개의 줄에 걸쳐 한 줄에 정수 A B 형태로 주어진다. A번 과목이 B번 과목의 선수과목이다.
// A < B인 입력만 주어진다. (1 ≤ A < B ≤ N)
//
//
// Output
// 1번 과목부터 N번 과목까지 차례대로 최소 몇 학기에 이수할 수 있는지를 한 줄에 공백으로 구분하여 출력한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Prerequisite(const vector<vector<int>>& g, vector<int>& indegree, int vertices)
{
    vector<int> result(g.size(), 0);
    queue<int> q;
    for (int i = 1; i < vertices+1; ++i) {
        if (indegree[i] == 0) {
            q.emplace(i);
            result[i] = 1;  // 진출차수가 0인 i 과목은 1학기 수강
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int n : g[now]) {  // now 와 연결된 과목의 진입차수 1 빼기
            indegree[n] -= 1;
            if (indegree[n] == 0) {
                q.emplace(n);
                result[n] = result[now] + 1;    // 새롭게 진입차수가 0이된 과목은 now 과목의 수강학기 +1
            }
        }
    }

    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> indegree(N+1);
    vector<vector<int>> g(N+1);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
        indegree[B]++;
    }


    auto res = Prerequisite(g, indegree, N);
    for (int i = 1; i < N + 1; ++i) {
        cout << res[i] << ' ';
    }
}

