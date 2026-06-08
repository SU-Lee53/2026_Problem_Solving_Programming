
// 현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다.
// 현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고,
// 돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 현우는 통장에서 K원을 인출하며,
//
// 통장에서 뺀 돈으로 하루를 보낼 수 있으면 그대로 사용하고, 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다.
// 다만 현우는 M이라는 숫자를 좋아하기 때문에, 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다
// 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다.
//
// 현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.




#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int N, M; cin >> N>> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    // 금액 K를 계산
    int total = accumulate(v.begin(), v.end(), 0);
    int start = *max_element(v.begin(), v.end());
    int end = total;
    int ans = 0;

    auto check = [&](int mid) -> bool {
        // 돈을 mid 원씩 M 번만 뽑고 살 수 있을까
        int cur = mid * M;
        return total <= cur;
    };

    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(mid)) {
            ans = mid;       // 정답 후보
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;
}
