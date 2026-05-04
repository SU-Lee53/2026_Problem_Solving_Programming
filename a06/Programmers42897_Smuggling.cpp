// 도둑질
// https://school.programmers.co.kr/learn/courses/30/lessons/42897
// 문제 설명
// 도둑이 어느 마을을 털 계획을 하고 있습니다. 이 마을의 모든 집들은 아래 그림과 같이 동그랗게 배치되어 있습니다.
//
// image.png
//
// 각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.
//
// 각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return 하도록 solution 함수를 작성하세요.
//
// 제한사항
// 이 마을에 있는 집은 3개 이상 1,000,000개 이하입니다.
// money 배열의 각 원소는 0 이상 1,000 이하인 정수입니다.
// 입출력 예
// money	        return
// [1, 2, 3, 1]	    4

#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();

    // 첫번째 집을 털기 위해 마지막 집을 포기
    vector<int> table1(N, 0);
    table1[0] = money[0];
    table1[1] = max(money[0], money[1]);
    for (int i = 2; i < N - 1; ++i) table1[i] = max(table1[i-1], table1[i-2]+money[i]);

    // 마지막 집을 털기 위해 첫번째 집을 포기
    vector<int> table2(N, 0);
    table2[1] = money[1];
    for (int i = 2; i < N; ++i) table2[i] = max(table2[i-1], table2[i-2]+money[i]);

    return max(table1[N-2], table2[N-1]);
}

int main()
{
    cout << solution({1,2,3,1});
}