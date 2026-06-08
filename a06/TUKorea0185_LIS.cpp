// 가장 큰 증가하는 부분 수열
// http://210.93.60.51/problem/0185
// Description
//
// 수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
//
// 예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에
// 합이 가장 큰 증가하는 부분 수열은 A = {'1', 100, '2', '50', '60', 3, 5, 6, 7, 8} 이고, 합은 113이다.
//
// Input
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai≤ 1,000)
//
// Output
// 첫째 줄에 수열 A의 합이 가장 큰 증가하는 부분 수열의 합을 출력한다.
//
// Sample Input 1
// 10
// 1 100 2 50 60 3 5 6 7 8
//
// Sample Output 1
// 113


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> arr(N, 0);
    copy_n(istream_iterator<int>{cin}, N, arr.begin());

    vector<int> dp = arr;   // 초기값은 1이 아닌 arr[i]가 되어야 함 -> dp하면서 바로바로 더함

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}

