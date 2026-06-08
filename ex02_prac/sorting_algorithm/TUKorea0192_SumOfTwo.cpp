// 두 수의 합
// http://210.93.60.51/problem/0192
// Description
//
// n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다.
// ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다.
// 자연수 x가 주어졌을 때, ai+ aj= x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.
//
// Input
// 첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다.
// 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)
//
// Output
// 문제의 조건을 만족하는 쌍의 개수를 출력한다.
//
// Sample Input 1
// 9
// 5 12 7 10 9 1 2 3 11
// 13
//
// Sample Output 1
// 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int x; cin >> x;

    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < v.size() / 2; ++i) {
        auto it = find(v.begin() + i, v.end(), x-v[i]);
        if (it != v.end()) ++count;
    }

    cout << count << endl;
}




