// 내려가기
// Description
//
// N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다.
// 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.
//
// 먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다.
// 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다. 바
// 로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다.
// 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.
//
// 별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며,
// 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오.
// 점수는 원룡이가 위치한 곳의 수의 합이다.
//
//
// Input
// 첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 숫자가 세 개씩 주어진다.
// 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.
//
//
// Output
// 첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.
//
//
// Sample Input 1
// 3
// 1 2 3
// 4 5 6
// 4 9 0
//
// Sample Output 1
// 18 6
//
// Hint
// 메모리 제한 (4MB)
// 슬라이딩 윈도우

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int N; cin >> N;

    vector<int> arr(3, 0);
    for (int j = 0; j < 3; ++j) {
        cin >> arr[j];
    }
    vector<int> dp_max = arr;
    vector<int> dp_min = arr;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr[j];
        }

        vector<int> p_max(3, 0);
        vector<int> p_min(3, 0);
        for (int c = 0; c < 3; ++c) {
            int up_max, up_left_max, up_right_max;
            int up_min, up_left_min, up_right_min;

            // 왼쪽에서 내려옴
            if (c == 0) {
                up_left_max = 0;
                up_left_min = std::numeric_limits<int>::max();
            }
            else {
                up_left_max = dp_max[c-1];
                up_left_min = dp_min[c-1];
            }

            // 오른쪽에서 내려옴
            if (c == 2) {
                up_right_max = 0;
                up_right_min = std::numeric_limits<int>::max();
            }
            else {
                up_right_max = dp_max[c+1];
                up_right_min = dp_min[c+1];
            }

            // 바로 위에서 내려움
            up_max = dp_max[c];
            up_min = dp_min[c];

            p_max[c] = arr[c] + max(max(up_max, up_left_max), up_right_max);
            p_min[c] = arr[c] + min(min(up_min, up_left_min), up_right_min);
        }

        dp_max = p_max;
        dp_min = p_min;

    }


    cout << *max_element(dp_max.begin(), dp_max.end()) << " ";
    cout << *min_element(dp_min.begin(), dp_min.end());
}




