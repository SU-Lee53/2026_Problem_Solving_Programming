
// Two pointer

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5, m = 5;
    vector<int> data {1,2,3,2,5};
    int count = 0;
    int interval_sum = 0;
    int end = 0;
    for (int start = 0; start < n; ++start) {
        while (end < n && interval_sum < m) {
            interval_sum += data[end];
            end += 1;
        }
        // 부분합이 m 이면 카운트 중가
        if (interval_sum == m) {
            count += 1;
        }
        interval_sum -= data[start];

    }

    cout << count << endl;
}