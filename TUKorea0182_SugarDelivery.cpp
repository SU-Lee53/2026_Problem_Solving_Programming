// 설탕 배달
// http://210.93.60.51/problem/0182
// Description
//
// 상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다.
// 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.
//
// 상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다.
// 예를 들어, 18킬로그램 설탕을 배달해야 할 때,
// 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.
//
// 상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
//
//
// Input
// 첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)
//
// Output
// 상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.


#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> dp(N+1, numeric_limits<int>::max());
    dp[0] = 0;

    int entries[2] = {3,5};
    for (int i = 0; i < 2; ++i) {
        int curr = entries[i];
        dp[curr] = 1;
        for (int j = curr + 1; j <= N; ++j) {
            if (dp[j - curr] != numeric_limits<int>::max())
                dp[j] = dp[j - curr] + 1;
        }
    }

    if (dp[N] != std::numeric_limits<int>::max()) cout << dp[N];
    else cout << -1;
}