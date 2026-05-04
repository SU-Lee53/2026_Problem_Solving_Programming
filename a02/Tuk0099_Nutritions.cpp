// 균형잡힌 영양소
// Description
//
// 균형 잡힌 영양소를 가진 식단의 가짓수 구하기
//
// 영양소 정보가 포함된 음식의 리스트가 주어졌을 때, 기준치에 대해 적합한 영양소를 가지는 식단(음식의 집합)을 구성하는 가짓수를 출력
// 식단은 음식을3가지까지 포함할 수 있음
// 기준치에 대해 적합한 식단이란:
// 식단을 구성하는 모든 음식의 탄수화물 합이 기준치가 되는 탄수화물 이하인가?
// 식단을 구성하는 모든 음식의 단백질 합이 기준치가 되는 단백질 이상인가?
// 식단을 구성하는 모든 음식의 지방 합이 기준치가 되는 지방 이하인가?
// 식단을 구성하는 모든 음식의 열량 합이 기준치가 되는 열량 이하인가? (열량 = 탄수화물 * 4 + 단백질 * 4 + 지방 * 9)
//
// Input
//
// 첫번째 줄에 음식의 개수 N (1<=N<=100)
//
// 다음 N개 줄에 걸쳐서 각 음식의 탄수화물, 단백질, 지방의 양 (각 영양소의 양은 100 이하)
//
// 마지막 줄에 기준치가 되는 탄수화물, 단백질, 지방, 열량의 양
//
//
// Output
//
// 음식을 기준치에 맞게 조합하여 만들 수 있는 식단의 가짓수 (정수) 출력

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Nutrition {
    int _c;
    int _p;
    int _f;

    Nutrition() = default;
    Nutrition(int c, int p, int f) : _c{c},_p{p},_f{f} {}

    Nutrition operator+(const Nutrition& other) {
        Nutrition n;
        n._c = _c + other._c;
        n._p = _p + other._p;
        n._f = _f + other._f;
        return n;
    }

    int Calories() const { return (_c * 4) + (_p * 4) + (_f * 9); }

    bool isValid(int c, int p, int f, int cal) {
        return (_c <= c) && (_p >= p) && (_f <= f) && (Calories() <= cal);
    }

};

template<typename T>
std::vector<std::vector<T>> combination(std::vector<T>& lst, int n)
{
    std::vector<std::vector<T>> ret;
    if (n > lst.size()) return ret;

    if (n == 1) {
        for (T& i : lst) {
            ret.emplace_back(std::initializer_list<T>{ i });
        }
    }
    else if (n > 1) {
        for (int i = 0; i < lst.size() - n + 1; ++i) {
            vector<T> slice(lst.begin() + i + 1, lst.end());
            for (vector<T> temp : combination(slice, n - 1)) {
                vector<T> temp2 = { lst[i] };
                temp2.insert(temp2.end(), temp.begin(), temp.end());
                ret.push_back(temp2);
            }
        }
    }

    return ret;
}
int main()
{
    int N;
    cin >> N;

    vector<Nutrition> v;
    for (int i = 0; i < N; ++i) {
        int c, p, f;
        cin >> c >> p >> f;
        v.emplace_back(c,p,f);
    }

    int c, p, f, cal;
    cin >> c >> p >> f >> cal;

    int answer = 0;
    for (int i = 1; i < 4; ++i) {
        if (i > N) break;
        for (auto res :combination(v, i)) {
            auto n = std::accumulate(res.begin(), res.end(), Nutrition{});
            if (n.isValid(c,p,f,cal)) {
                answer++;
            }
        }
    }

    std::cout << answer;
}



