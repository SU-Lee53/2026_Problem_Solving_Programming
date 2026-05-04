// DFS, BFS

// 1. DFS
#include <iostream>
#include <vector>
#include <deque>

template<typename T>
void DFS(const T& v, const std::vector<std::vector<T>>& graph, std::vector<bool>& visited)
{
    // 현재 노드 방문 처리
    visited[v] = true;
    std::cout << v << ' ';

    for (auto& i : graph[v]) {
        if (!visited[i]) {
            DFS(i, graph, visited);
        }
    }
}

template<typename T>
void DFS_Stack(const T& v, const std::vector<std::vector<T>>& graph, std::vector<bool>& visited)
{
    std::deque<T> stack{v};
    while (stack.size() != 0) {
        T value = stack.back();
        stack.pop_back();

        if (!visited[value]) {
            visited[value] = true;
            std::cout << value << ' ';

            // 인접한 정점번호가 작은것부터 구현하려면 내림차순 접근이 필요함
            for (auto it = graph[value].rbegin(); it != graph[value].rend(); ++it) {
                if (!visited[*it]) {
                    stack.push_back(*it);
                }
            }
        }

    }
}

template<typename T>
void BFS(const T& v, const std::vector<std::vector<T>>& graph, std::vector<bool>& visited)
{
    std::deque<T> queue{v};
    while (queue.size() != 0) {
        T value = queue.front();
        queue.pop_front();

        if (!visited[value]) {
            visited[value] = true;
            std::cout << value << ' ';

            // 인접한 정점번호가 작은것부터 구현하려면 내림차순 접근이 필요함
            for (const T& n : graph[value]) {
                if (!visited[n]) {
                    queue.push_back(n);
                }
            }
        }
    }
}



int main()
{
    using namespace std;

    vector<vector<int>> graph{
        {},
        {2,3,8},
        {1,7},
        {1,4,5},
        {3,5},
        {3,4},
        {7},
        {2,6,8},
        {1,7}
    };

    vector<bool> visited(graph.size(), false);

    DFS(1, graph, visited);

    cout << '\n';
    visited = vector<bool>(graph.size(), false);

    DFS_Stack(1, graph, visited);

    cout << '\n';
    visited = vector<bool>(graph.size(), false);

    BFS(1, graph, visited);
}

