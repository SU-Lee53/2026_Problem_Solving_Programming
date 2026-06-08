// [2021 예선 E] 정수 삼각형
// http://210.93.60.51/problem/0068
// Description
// 위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 한다.
// 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능하다.
// 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능하다.
// 삼각형의 정보가 담긴 표준 입력으로 주어질 때, 거쳐간 숫자의 최댓값을 표준출력한다.
//
// 위의 그림의 예에서는 최댓값이 30 이다.
//
// Input
// 첫번째 줄에는 삼각형의 높이를 나타내는 H가 나타난다.
// 이어지는 H줄에는 삼각형을 이루는 숫자가 차례로 나타난다.
//
// 제한사항
// 삼각형의 높이 H는 1 이상 500 이하이다.
// 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수이다.
//
// Output
// 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 최댓값을 출력한다.
//
// Sample Input 1
// 5
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
//
// Sample Output 1
// 30

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H; cin >> H;
    vector<vector<int>> tri(H, vector<int>(H, 0));
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < r+1; ++c) {
            cin >> tri[r][c];
        }
    }

    //     0        0
    //    0 1       1
    //   0 1 2      2
    //  0 1 2 3     3
    // 0 1 2 3 4    4

    vector<vector<int>> dp(H, vector<int>(H, 0));
    dp[0][0] = tri[0][0];
    for (int r = 1; r < H; ++r) {
        for (int c = 0; c < r + 1; ++c) {
            int dp_max = 0;
            if (c - 1 >= 0) dp_max = max(dp_max, dp[r-1][c-1] + tri[r][c]);
            if (c <= r) dp_max = max(dp_max, dp[r-1][c] + tri[r][c]);

            dp[r][c] = dp_max;
        }
    }

    cout << *max_element(dp[H-1].begin(), dp[H-1].end());
}


