/*
    Interval Sum
    - 구간 합 문제: 연속적으로 나열된 N개의 수가 있을 때 특정 구간의 모든 수를 합한 값을 계산하는 문제

    - 특징
        - N개의 정수로 구성된 수열이 있다
        - M개의 쿼리 정보가 주어진다
            - 각 쿼리는 Left 와 Right 로 구성된다
            - 각 쿼리에 대하여 [Left, Right] 구간에 포함된 데이터들의 합을 출력한다.
        - 수행 시간 제한은 O(N + M)

    - 빠르게
        - Prefix sum
            - 배열의 맨 앞부터 특정 위치까지의 합을 미리 구함
            - [0, 10, 20, 30, 40, 50] -> [0, 10, 30, 60, 100, 150]
            - 일종의 DP
            - 자세한 방법
                - N개의 수 위치 각각에 대하여 접두사 합을 계산하여 P에 저장한다
                - 매 M개의 쿼리 정보를 확인할 때 구간 합은 P[Right] – P[Left – 1] 이다.
                - 위 예시에서 20 ~ 50 까지의 합
                    - P[5] - P[2-1] = 140

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5;
    vector<int> data{10, 20, 30, 40, 50};

    // Prefix sum
    int sum_value = 0;
    vector<int> prefix_sum;
    prefix_sum.reserve(n);
    for (int i : data) {
        sum_value += i;
        prefix_sum.push_back(sum_value);
    }

    // Interval sum in range (3, 4)
    int left = 3, right = 4;
    cout << prefix_sum[right] - prefix_sum[left - 1] << endl;
    

}