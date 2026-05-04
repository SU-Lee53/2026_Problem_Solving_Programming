// 여행경로
// 문제 설명
// 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.
//
// 항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
//
// 제한사항
// 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
// 주어진 공항 수는 3개 이상 10,000개 이하입니다.
// tickets의 각 행 {a, b}는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
// 주어진 항공권은 모두 사용해야 합니다.
//
// 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
// 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


pair<vector<string>, int> DFS(string& port, vector<string> path, vector<vector<int>>& graph, const vector<string>& ports, int& nTickets)
{
    // 출발 공항 인덱스
    int r = distance(ports.begin(), find(ports.begin(), ports.end(), port));
    for (int c = 0; c < ports.size(); ++c) {
        if (graph[r][c] > 0) {  // r->c 티켓이 존재하면
            graph[r][c] -= 1;   // r->c 티켓 사용
            port = ports[c];
            nTickets -= 1;
            std::vector<string>nextPath(path);
            nextPath.push_back(port);
            auto [ans, tickets] = DFS(port, nextPath, graph, ports, nTickets);
            nTickets = tickets;
            if (nTickets == 0) {
                return {ans, nTickets};
            }
            else { // ICN -> AAA 는 전체 순화가 불가능하나, ICN -> CCC 로 시작하면 가능한 겨우
                graph[r][c] += 1;
                nTickets += 1;
            }
        }
    }

    return {path, nTickets};
}


vector<string> solution(vector<vector<string>> tickets)
{
    // 1. ticket 을 조회해서 중복을 허락하지 않는 공항 리스트 생성
    set<string> portSet;

    for (const auto& v : tickets) {
        portSet.insert(v[0]);
        portSet.insert(v[1]);
    }

    vector<string> ports(portSet.begin(), portSet.end());

    // 2. tickets 를 보면서 graph 생성
    int N = ports.size();
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (const auto& path : tickets) {
        int r = distance(ports.begin(), find(ports.begin(), ports.end(), path[0]));
        int c = distance(ports.begin(), find(ports.begin(), ports.end(), path[1]));
        graph[r][c] += 1;
    }


    // 3. ICN 에서 시작해서 모든 티켓을 사용하는 DFS 수행
    int nTickets = tickets.size();
    string port = "ICN";
    std::vector<string> path{"ICN"};

    auto [answer, ticketCount] = DFS(port, path, graph, ports, nTickets);

    return answer;
}

int main()
{
    vector<vector<string>> tickets1 = {
        {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}
    };
    vector<vector<string>> tickets2 = {
        {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}
    };

    vector<vector<string>> tickets3 = {
        {"ICN", "AAA"}, {"ICN", "CCC"}, {"CCC", "DDD"}, {"AAA", "BBB"}, {"AAA", "BBB"}, {"DDD", "ICN"}, {"BBB", "AAA"}
    };

    auto sol = solution(tickets1);
    for (const auto& s : sol) {
        cout << s << ' ';
    }

    std::cout << std::endl;

    sol = solution(tickets2);
    for (const auto& s : sol) {
        cout << s << ' ';
    }

    std::cout << std::endl;

    sol = solution(tickets3);
    for (const auto& s : sol) {
        cout << s << ' ';
    }

}