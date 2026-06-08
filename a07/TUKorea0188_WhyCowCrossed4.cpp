// 소가 길을 건너간 이유 4
// http://210.93.60.51/problem/0188
// Description
//
// 농부 존의 소들은 효율적으로 길을 건너는 방법을 터득하고 있다. 그들은 길 건너기의 달인인 닭의 도움을 받기로 했다.
//
// 안타깝게도 닭은 매우 바쁜 동물이라, 소를 도와줄 시간이 별로 없다. 농장에 C마리(1 ≤ C ≤ 20,000)의 닭이 있고,
// 1번부터 C번까지 번호가 붙어 있다. i번 닭은 정확히 Ti초에만 소를 도와줄 수 있다.
// 하지만 닭은 길 건너기의 달인이므로 소를 데리고도 순식간에 길을 건널 수 있다.
// 소는 할 일이 없어서 여유롭게 길을 건널 수 있다.
// 소는 총 N마리(1 ≤ N ≤ 20,000)가 있고, 마찬가지로 1번부터 N번까지 번호가 붙어 있다.
// j번 소는 Aj초부터 Bj초까지 길을 건널 수 있다.
// j번 소가 i번 닭의 도움을 받아 길을 건너려면  Aj≤ Ti≤ Bj를 만족해야 한다.
//
// 소는 최대 한 마리의 닭에게만 도움을 받을 수 있고, 닭 역시 최대 한 마리의 소만 도와줄 수 있다.
// 도움을 받을 수 있는 소가 최대 몇 마리인지 구해보자.
//
//
// Input
// 첫 줄에 C와 N이 주어진다. 다음 C줄에는 T1…TC가 주어지고, 그 다음 N줄에는 Aj와 Bj(Aj≤ Bj)가 주어진다.
// A, B, T는 모두 최대 1,000,000,000인 음이 아닌 정수이고, 같을 수도 있다.
//
// Output
// 도움을 받을 수 있는 소가 최대 몇 마리인지 출력한다.
//
//
// Sample Input 1
// 5 4
// 7
// 8
// 6
// 2
// 9
// 2 5
// 4 9
// 0 3
// 8 13
//
// Sample Output 1
// 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int C, N;
    cin >> C >> N;

    vector<int> T(C);
    vector<pair<int, int>> L(N);
    for (int i = 0; i < C; ++i) cin >> T[i];
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        L[i] = {a,b};
    }

    sort(T.begin(), T.end());
    sort(L.begin(), L.end());

    // Ti를 하나씩 꺼내서 Ti보다 작거나 같은 Ai를 갖는 소의 Bi를 최소 힙에 넣는다
    int index = 0;  // 소 인덱스
    int answer = 0; // 도움 받은 소의 마리수
    priority_queue<int, vector<int>, greater<>> pq;
    for (const int Ti : T) {
        while (index < N && L[index].first <= Ti) {
            pq.emplace(L[index].second);
            ++index;
        }

        // 최소 힙에서 꺼낸 Bi가 Ti 이상이면 그 소를 건너준다
        while (!pq.empty()) {
            int Bi = pq.top();
            pq.pop();
            if (Ti <= Bi) {
                ++answer;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}
