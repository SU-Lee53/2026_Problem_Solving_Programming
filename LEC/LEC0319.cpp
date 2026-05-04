
// 각 자리가 숫자(0부터 9)로만 이루어진 문자열 S가 주어졌을 때, 왼쪽부터 오른쪽으로 하나씩 모든 숫자를 확인하며 숫자 사이에 ‘x’ 혹은 ‘+’
// 연산자를 넣어 결과적으로 만들어질 수 있는 가장 큰 수를 구하는 프로그램을 작성하세요.
// 단, +보다 x를 먼저 계산하는 일반적인 방식과는 달리, 모든 연산은 왼쪽에서부터 순서대로 이루어진다고 가정합니다.

/*
#include <iostream>
#include <sstream>

int main()
{
    std::string s;
    std::cin >> s;

    uint64_t result = 0;
    for (char c : s) {
        uint64_t num = c - '0';
        if (num <= 1 || result <= 1) {
            result += num;
        }
        else {
            result *= num;
        }
    }

    std::cout << result << '\n';
}
*/

// 한 마을에 모험가가 N명 있습니다. 모험가 길드에서는 N명의 모험가를 대상으로 ‘공포도’를 측정했는데,
// ‘공포도’가 높은 모험가는 쉽게 공포를 느껴 위험 상황에서 제대로 대처할 능력이 떨어집니다.
//
// 모험가 길드장인 겜공이는 모험가 그룹을 안전하게 구성하고자 공포도가 X인 모험가는
// 반드시 X명 이상으로 구성한 모험가 그룹에 참여해야 여행을 떠날 수 있도록 규정했습니다.
//
// 겜공이는 최대 몇 개의 모험가 그룹을 만들 수 있는지 궁금합니다.
// N명의 모험가에 대한 정보가 주어졌을 때, 여행을 떠날 수 있는 그룹 수의 최댓값을 구하는 프로그램을 작성하세요.
//
// 예를 들어 N = 5이고, 각 모험가의 공포도가 다음과 같다고 가정
// 2 3 1 2 2
//
// 이 경우 그룹 1에 공포도가 1, 2, 3인 모험가를 한 명씩 넣고,
// 그룹 2에 공포도가 2인 남은 두 명을 넣게 되면 총 2개의 그룹을 만들 수 있다.
// 또한 몇 명의 모험가는 마을에 그대로 남아 있어도 되기 때문에, 모든 모험가를 특정한 그룹에 넣을 필요는 없다.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> data;
    data.reserve(N);
    std::copy_n(std::istream_iterator<int>(std::cin), N, std::back_inserter(data));

    std::sort(data.begin(), data.end());

    int result = 0;
    int count = 0;

    for (int n : data) {
        count += 1;         // 현재 그룹에 해당 공포도 모험가를 포함
        if (count >= n) {   // 현재 그룹 모험가 수 > 마지막 포함된 공포도 수
            ++result;       // 그룹 수 + 1
            count = 0;      // 현재 그룹 모험가 수 초기화
        }
    }

    std::cout << result;
}
