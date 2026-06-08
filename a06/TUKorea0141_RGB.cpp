// RGB거리
// http://210.93.60.51/problem/0141
// Description
//
// RGB거리에는 집이 N개 있다.
// 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
//
// 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.
// 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
//
// 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
// N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
// i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
//
// Input
// 첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
// 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.
//
//
// Output
// 첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
//
//
// Sample Input 1
// 3
// 26 40 83
// 49 60 57
// 13 89 99
//
// Sample Output 1
// 96

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;

    vector<vector<int>> arr(N, vector<int>(3, 0));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < 3; ++c) {
            cin >> arr[r][c];
        }
    }

    // dp[i][j] = arr[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+1)%3])
    // dp 테이블은 입력받은 2차원 배열로 초기화시켜도 됨
    vector<vector<int>> dp = arr;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {   // R, G, B
            dp[i][j] = dp[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }

    cout << *min_element(dp[N-1].begin(), dp[N-1].end());
}

