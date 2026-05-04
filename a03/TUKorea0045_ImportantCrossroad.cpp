// [2020 본선 E] 중요한 교차로
// Description
//
// 긴 장마철이 지나고 망가진 도로 보수를 위해서 시흥시는 시내의 모든 교차로를 재포장하기로 결정했습니다.
// 교차로를 포장하려면 해당 교차로를 통과하는 모든 교통을 통제해야 합니다.
// 그런데 교차로들 중에서 중요한 교차로는 교통 통제에 주의해야 합니다.

// 예를 들어서 교차로 J에서 교차로 K를 가려면 반드시 교차로 I를 통과해야 한다면,
// 교차로 I를 통제하면 J에서 K로 가는 길이 막히므로, 교차로 I를 중요한 교차로라고 합니다.

// 시흥시의 도로는모두 양방향 통행이 가능하며, 모든 교차로를 이용할 수 있다면 어느 교차로에서 든지 다른 교차로로 갈 수 있습니다.
// 시흥시 도로의 이름은 오직 2개의 교차로를 연결하고 다른 교차로는 통과하지 않습니다.
//
// 예를 들어서5 개의 교차로I1,I2,I3,I4,I5가 있고  6개의 도로가있다고 가정합니다.
//
// Image
//
// 도로 1은I1과I2를연결합니다.
// 도로 2는I2와I3을연결합니다.
// 도로 3은I1과I3을연결합니다.
// 도로 4는I2와I4를연결합니다.
// 도로 5는I2와I5를연결합니다.
// 도로 6은I5와I4를연결합니다.

// 그러면 I2를 교통 통제하면 I4에서 I1 (혹은 I3)으로 가는 길이 없으므로 I2는 중요한 교차로 입니다.
// 또한 I5에서 I1 그리고 I5에서 I3로 가는 길도 끊깁니다. I2이외의 더 이상의 중요한 교차로는 없습니다.
// 당신이 할 일은 시흥시 교차로와 도로 정보를 살펴보고 중요한 교차로 목록을 결정하는 것입니다.
//
// Input
// 입력의 첫 번째 줄에는 두 개의 정수N과M이있습니다.
// N은 시흥시의 교차로 수이고M은 도로 수입니다.
// 교차로의 번호는 1,2, ...,N이라고 가정합니다.
// 다음M개 줄(2, ...,M+1번째 줄)은 시흥시의 도로를 나타냅니다.
// i+1번째 줄은 도로 i로연결된 교차로 쌍을 나타내는1, ...,N범위의 두 정수를 포함합니다.
// N≤ 300, M≤ 50000 입니다.
//
// Output
// 출력의 첫 번째 줄에는 중요한 교차로 개수를 나타내는정수C를 출력합니다.
// 다음C개 줄에는한 줄 당 하나씩 중요한 교차로 번호를 출력합니다.
// 중요한 교차로가 여러개 이면 교차로 번호 오름 차순으로 출력합니다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int v, int i, const vector<vector<bool>>& graph, int N, vector<bool>& visited)
{
    std::vector<int> stack{v};

    while (stack.size() != 0) {
        v = stack.back();
        stack.pop_back();

        if (visited[v] == false) {
            visited[v] = true;
        }

        for (int l = 0; l < N; ++l) {
            if (l != i                                                      &&
                visited[l] == false                                      &&
                find(stack.begin(), stack.end(), l) == stack.end() &&
                graph[v][l] == true) {
                stack.push_back(l);
            }
        }

    }


}

int main()
{
    int N, M;   // N : 교차로(노드) 의 수 / M : 도로(간선) 의 수
    cin >> N >> M;

    vector<vector<bool>> graph(N, vector<bool>(N, false));  // N * N 2차원 그래프 / graph[i][j] => i->j 도로가 존재하면 true

    for (int i = 0; i < M; ++i) {   // M개의 도로에 대해서 graph 설정
        int r, c;
        cin >> r >> c;
        graph[r-1][c-1] = true; // 교차로 번호는 1부터 시작하므로 0-Base 인덱스로 변경함
        graph[c-1][r-1] = true;
    }

    vector<int> answer;

    // A 교차로가 중요한 교차로가 아니라면,  A 교차로를 제외한 다른 임의의 교차로에서 시작해서 나머지 모든 교차로를 방문할 수 있다.
    for (int i = 0; i < N - 1; ++i) {
        // 1. 모든 교차로(노드) 를 unvisited 로 설정
        vector<bool> visited(N, false);

        // 2. 임의의 교차로에서 DFS로 완전순회하면 i 를 제외한 모든 교차로(노드)를 방문해야함
        int v = (i + 1) % N;    // i가 아닌 임의의 시작 교차로
        DFS(v, i, graph, N, visited);

        // 3. i를 제외한 unvisited 교차로가 존재하면 i는 중요한 교차로임
        for (int c = 0; c < N; ++c) {
            if (i != c && visited[c] == false) {
                answer.push_back(i + 1);
                break;
            }
        }
    }

    std::cout << answer.size() << std::endl;
    for (const int n : answer) {
        std::cout << n << std::endl;
    }


}









