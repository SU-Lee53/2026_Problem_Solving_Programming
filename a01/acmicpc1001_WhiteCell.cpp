// 하얀 칸
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 2 초	128 MB	33732	23692	21080	72.445%
// 문제
// 체스판은 8×8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다.
// 가장 왼쪽 위칸 (0,0)은 하얀색이다.
// 체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지 출력하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄부터 8개의 줄에 체스판의 상태가 주어진다. ‘.’은 빈 칸이고, ‘F’는 위에 말이 있는 칸이다.
//
// 출력
// 첫째 줄에 문제의 정답을 출력한다.

#include <iostream>
#include <string>

bool IsWhite(int row, int col)
{
    return (row & 1) ? (col & 1) : !(col & 1);
}

int main()
{
    int answer{};
    std::string in;
    for (int row = 0; row < 8; ++row) {
        std::cin >> in;
        for (int col = 0; col < 8; ++col) {
            if (in[col] != '.') {
                answer = IsWhite(row, col) ? answer + 1 : answer;
            }
        }
    }

    std::cout << answer;
}