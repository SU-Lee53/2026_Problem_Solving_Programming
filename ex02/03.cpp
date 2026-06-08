
// 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 마지막 도착 계단은 반드시 밟아야 한다.
// i-1 계단에서 올라오던가 (i-3 에서 올라와야함)
// i-2 계단에서 올라오던가

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> v(N+1, 0);
    v[0] = 0;
    for (int i = 1; i <= N; ++i) cin >> v[i];

    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    for (int i = 3; i <= N; ++i) {
        int c1 = dp[i-3] + v[i-1] + v[i];
        int c2 = dp[i-2] + v[i];
        dp[i] = max(c1, c2);
    }

    cout << dp[N];
}
