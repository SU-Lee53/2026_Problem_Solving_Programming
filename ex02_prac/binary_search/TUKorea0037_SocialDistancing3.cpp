// 사회적 거리두기 III
// http://210.93.60.51/problem/0037
// Description
//
// 전세계적으로 퍼진 신종 코로나-19 감염병 예방을 위해서 김교수는 기말고사에서 사회적 거리두기를 시행하려고 합니다.
// N (2≤N≤10^5) 명의 학생들은일렬로 배치된책상에 기말고사를 보기해서 최대한 학생들 간에 떨어져서 앉으려고 합니다.
// 그런데 일렬로 배치된 책상은 중간 중간에 책상이 배치되지 않았습니다.
// 책상이 연속 배치된 것들 끼리 그룹핑하면 M (1≤M≤10^5) 개의 그룹으로 나눌 수 있습니다.
// 김교수는 사회적 거리두기를 시행하기 위해서 가장 가까운 학생간의 거리, D가 최대가 되도록 N명의 학생들을 배치 하려고 합니다.
// 가장 가까운 학생간의 거리, D를 구하십시오.
//
// Input
// 입력의 첫번째 줄에는 학생 명수 N과 책상 그룹핑 개수 M을 포함합니다.
// 이어지는 M개 줄에는 그룹핑된 책상의 시작 위치 a와 끝 위치 b를 나타냅니다. (0≤a≤b≤10^18)
// 각각의 책상 그룹들의 위치들은 서로 겹치지 않으며 학생들은  책상 그룹의 시작, 중간, 끝 위치 등 아무 곳에나 앉아도 됩니다.
//
// Output
// N명의 학생을 배치했을 때 가장 가까운 학생간의 거리, D가 최대가 되는 D를 출력하십시오.
// D > 0 을 항상 만족 합니다.
// 입력의 예가 다음과 같다고 가정합시다.
//
// 5 3
// 0 2
// 4 7
// 9 9
// 그러면 5명의 학생들을 3개의 책상 그룹에 앉히는데 학생 위치를 0, 2, 4, 6, 9 에 앉힐 때
// 가장 가까운 학생간의 거리의 최대값 D = 2를 얻습니다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<pair<int64_t, int64_t>> groups(M);
    for (int i = 0; i < M; ++i) {
        cin >> groups[i].first >> groups[i].second;
    }

    sort(groups.begin(), groups.end(), [](const auto& lhs, const auto& rhs) {
       return lhs.first < rhs.first;
    });

    auto checker = [&](int64_t mid) {
        // mid 이상 거리를 벌리면서 N명을 앉힐 수 있는가
        // 왼쪽부터 거리를 mid 만큼 벌리며 앉혀본다

        int64_t count = 0;
        int64_t last = -INT_MAX;    // 마지막으로 앉힘 위치
        for (auto [s, e] : groups) {
            int64_t start = max(s, last + mid); // 시작점과 마지막으로 앉힌 자리 + 벌려야할 거리(다음에 앉힐 자리) 중 더 큰 번호의 자리를 선택
            if (start > e) continue;    // 현재 그룹에 더이상 못앉힘 -> 다음 그룹 탐색

            int64_t able = (e - start) / mid + 1;   // 현재 그룹에서 남은 자리 중 (e - start) mid 간격으로 몇명이나 더 앉힐 수 있나
            count += able;                          // able 결과 누적
            last = start + (able - 1) * mid;        // 마지막으로 앉힌 자리는 시작점 + (가능한 인원 * 의무적 거리(확인값))
            if (count >= N) return true;            // 누적 >= N : 다 앉기가 가능함 확인 성공
        }
        return false;
    };


    int64_t start = 0;
    int64_t end = pow(10, 18);
    int64_t ans = 0;
    while (start < end) {
        int64_t mid = (end + start) / 2;
        if (checker(mid)) {
            ans = mid;
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    cout << ans << endl;
}


