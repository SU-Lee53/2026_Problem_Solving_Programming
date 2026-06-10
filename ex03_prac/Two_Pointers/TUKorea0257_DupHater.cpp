// 겹치는 건 싫어
// http://210.93.60.51/problem/0257
//
// Description
// 홍대병에 걸린 도현이는 겹치는 것을 매우 싫어한다.
// 특히 수열에서 같은 원소가 여러 개 들어 있는 수열을 싫어한다.
// 도현이를 위해 같은 원소가K개 이하로 들어 있는 최장 연속 부분 수열의 길이를 구하려고 한다.
//
// 100,000이하의 양의 정수로 이루어진 길이가N인 수열이 주어진다.
// 이 수열에서 같은 정수를K개 이하로 포함한 최장 연속 부분 수열의 길이를 구하는 프로그램을 작성해보자.
//
// Input
// 첫째 줄에 정수N(1 <= N <= 200,000)과K(1 <= K <= 100)가 주어진다.
// 둘째 줄에는{a_1, a_2, ... a_n}이 주어진다 (1 <= a_i <= 100,000)
//
// Output
// 조건을 만족하는 최장 연속 부분 수열의 길이를 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    copy_n(istream_iterator<int>{cin}, N, v.begin());

    vector<int> counts(100'000, 0);

    int end = 0;
    counts[v[0]]++;
    int result = 0;
    for (int start = 0; start < N - 1; ++start) {
        while (counts[v[end]] <= K && end < N) {
            ++counts[v[++end]];
        }

        result = max(result, end - start);
        --counts[v[start]];
    }

    cout << result;
}



