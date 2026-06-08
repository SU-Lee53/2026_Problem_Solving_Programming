// Priority queue

#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <ranges>

using namespace std;

default_random_engine dre{random_device{}()};
uniform_int_distribution<int> uid(0, 1'000'000);


template<typename It>
void heapsort(It begin, It end)
{
    using Ty = typename It::value_type;

    priority_queue<Ty, vector<Ty>, greater<>> q{begin, end};
    std::generate_n(begin, distance(begin, end), [&q]() {
        auto res = q.top();
        q.pop();
        return res;
    });
}

void print20(const vector<int>& v)
{
    cout << "{";
    for (int i = 0; i < 20; ++i) {
        cout << v[i] << " ";
    }
    cout << "}\n";
}

int main()
{
    std::vector<int> v(100'000);
    std::generate_n(v.begin(), 100'000, [](){return uid(dre);});
    print20(v);

    heapsort(v.begin(), v.end());
    print20(v);
}