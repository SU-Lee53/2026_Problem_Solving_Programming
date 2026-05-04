// 공유기 설치
// Description
//
// 도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
//
// 도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다.
// 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고,
// 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
//
// C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.
//
// Input
// 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다.
//
// 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi(0 ≤ xi≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.
//
// Output
//
// 첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// mid 인접 거리로 C개의 공유기를 설치 할 수 있는가
bool check(const vector<int> & xi, int mid, int N, int C)
{
    // |---------------|
    // last            i
    // 새로운 공유기를 설치하는 경우 : 마지막 공유기 설치 위치에서 i번째 집 사이 거리가 mid 이상이면
    int last = xi[0];    // 첫번째 집에 우선 공유기 설치
    int nC = 1;
    for (int i = 1; i < N; ++i) {
        if (xi[i] - last >= mid) {  // 마지막 공유기 설치 위치에서 i 번째 집 사이 거리가 mid 이상이면
            last = xi[i];
            nC++;
            if (nC == C) {  // C개 공유기 설치를 다 했으면 뒤에 집에 남아있는지 여부과 관계없이 만족
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N, C;
    cin >> N >> C;
    std::vector<int> xi(N);
    copy_n(istream_iterator<int>{cin}, N, xi.begin());
    sort(xi.begin(), xi.end());

    auto start = 0;
    auto end = *max_element(xi.begin(), xi.end());
    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(xi, mid, N, C)) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer;
}
