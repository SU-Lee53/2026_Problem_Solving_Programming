// 십자말 풀이(crossword)
// Description
//
// A와 B라는 두 단어가 주어집니다.
//
// 단어 A는 가로로, 단어 B는 세로로 출력해야 두 단어가 교차합니다(즉, 정확히 하나의 문자를 공유해야 합니다.).
//
// 공유 문자는 A와 B에 모두 포함되어야 하며,  A와 B 단어에서 공유 문자는 각각 처음 나타나야 합니다.
//
// 예를 들어 A = "ABBA" 및 B = "CCBB"라는 단어가 주어지면 아래와 같이 4줄을 출력해야 합니다.
//
// Input
// 첫 번째 줄에는 단일 공백으로 구분된 30자 이하의 두 단어 A와 B가 포함됩니다.
// 두 단어 모두 영문 대문자만 포함합니다.
// 두 단어 모두에 적어도 하나의 문자가 포함됩니다.
//
// Output
// N을 단어 A의 길이라고 하고 M을 단어 B의 길이라고 합니다.
// 출력에는 각각 N 문자가 포함된 M 줄이 포함되어야 합니다.
// 문자 격자는 위에서 설명한 대로 교차된 두 단어를 포함해야 합니다.
// 격자의 다른 모든 문자는 마침표(따옴표 없이 '.' 문자)여야 하므로 모든 행을 N 문자 길이로 채웁니다.


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::string A, B;
    std::cin >> A >> B;

    vector<string> v;
    v.reserve(B.size());
    v.insert(v.begin(), B.size(), string(A.size(), '.'));

    int nCrossA{}, nCrossB{};
    for (auto i = 0; i < A.size(); ++i) {
        auto pos = B.find_first_of(A[i]);
        if (pos != std::string::npos) {
            nCrossA = i;
            nCrossB = pos;
            break;
        }
    }

    v[nCrossB] = A;
    int cnt{};
    for (auto& s : v) {
        s[nCrossA] = B[cnt++];
    }

    for (const auto& s : v) {
        std::cout << s << '\n';
    }

}