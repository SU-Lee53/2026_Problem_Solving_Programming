// 1, 2, 3 더하기 4
// http://210.93.60.51/problem/0248
// Description
//
// 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 4가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 합을 이루고 있는 수의 순서만 다른 것은 같은 것으로 친다.
//
// 1+1+1+1
// 2+1+1 (1+1+2, 1+2+1)
// 2+2
// 1+3 (3+1)
// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
//
// Input
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 10,000보다 작거나 같다.
//
// Output
// 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
//
// Sample Input 1
// 3
// 4
// 7
// 10
//
// Sample Output 1
// 4
// 8
// 14


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;

    for (int i = 0; i < T; ++i) {
        int n; cin >> n;
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int num = 1; num <= 3; ++num) {
            for (int j = num; j <= n; ++j) {
                dp[j] += dp[j - num];
            }
        }

        cout << dp[n] << endl;
    }

}



