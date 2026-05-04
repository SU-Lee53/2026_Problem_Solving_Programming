// <문제> 개미 전사
// 개미 전사는 부족한 식량을 충당하고자 메뚜기 마을의 식량창고를 몰래 공격하려고 합니다.
// 메뚜기 마을에는 여러 개의 식량창고가 있는데 식량창고는 일직선으로 이어져 있습니다.
//
// 각 식량창고에는 정해진 수의 식량을 저장하고 있으며 개미 전사는 식량창고를 선택적으로 약탈하여 식량을 빼앗을 예정입니다.
// 이때 메뚜기 정찰병들은 일직선상에 존재하는 식량창고 중에서 서로 인접한 식량창고가 공격받으면 바로 알아챌 수 있습니다.
//
// 따라서 개미 전사가 정찰병에게 들키지 않고 식량창고를 약탈하기 위해서는 최소한 한 칸 이상 떨어진 식량창고를 약탈해야 합니다.
// 예를 들어 식량창고 4개가 다음과 같이 존재한다고 가정
//
// 이때 개미 전사는 두 번째 식량창고와 네 번째 식량창고를 선택했을 때 최댓값인 총 8개의 식량을 빼앗을 수 있습니다.
// 개미 전사는 식량창고가 이렇게 일직선상일 때 최대한 많은 식량을 얻기를 원합니다.
//
// 개미 전사를 위해 식량창고 N개에 대한 정보가 주어졌을 때 얻을 수 있는 식량의 최댓값을 구하는 프로그램을 작성하세요

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <random>

using namespace std;

default_random_engine dre{random_device{}()};
uniform_int_distribution<int> uid(1, 99);

int main()
{
    // int N; cin >> N;
    // std::vector<int> K(N, 0);
    // copy_n(istream_iterator<int>{cin}, N, K.begin());

    int N = uid(dre);
    std::vector<int> K(N, 0);
    generate_n(K.begin(), N, [](){return uid(dre);});
    
    std::vector<int> table(N, 0);
    table[0] = K[0];
    table[1] = K[1];

    // table[i] : i번째 식량창고까지 털었을 때 최댓값
    // 점화식 : max(table[i-1], table[i-2]+k[i])
    for (int i = 2; i < N; ++i) {
        table[i] = std::max(table[i - 1], table[i - 2] + K[i]);
    }

    for (int n : table) std::cout << n << ' ';

}
