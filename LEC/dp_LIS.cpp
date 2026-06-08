// <문제> 병사 배치하기:
//
// 문제 설명
// N명의 병사가 무작위로 나열되어 있다. 각 병사는 특정한 값의 전투력을 보유하고 있다.
//
// 병사를 배치할 때는 전투력이 높은 병사가 앞쪽에 오도록 내림차순으로 배치 하고자 한다.
// 다시 말해 앞쪽에 있는 병사의 전투력이 항상 뒤쪽에 있는 병사보다 높아야 한다.
//
// 또한 배치 과정에서는 특정한 위치에 있는 병사를 열외시키는 방법을 이용한다.
// 그러면서도 남아 있는 병사의 수가 최대가 되도록 하고 싶다.
//
// 전형적인 가장 긴 증가하는 부분 수열 문제 (LIS)
// D[i] = array[i]를 마지막 원소로 가지는 부분 수열의 최대 길이
// 점화식
// D[i] = max(D[i], D[j]+1) if array[j] < array[i]
// 이문제는 내림차순 이므로 array[j] > array[i] 로 바꾸면 됨 ( 0 <= j < i )
// dp 테이블은 1로 초기화가 필요

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> arr(N, 0);
    copy_n(istream_iterator<int>{cin}, N, arr.begin());

    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    for (int n : dp) {
        cout << n << " ";
    }

}

