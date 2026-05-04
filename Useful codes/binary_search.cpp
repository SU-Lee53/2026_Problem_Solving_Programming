#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

default_random_engine dre{random_device{}()};
uniform_int_distribution<int> uid(0, 100);

size_t binary_search(const vector<int>& v, int target, size_t start, size_t end)
{
    while (start <= end) {
        int mid = (start + end) / 2;
        if (v[mid] == target) return mid;
        else if (v[mid] > target) end = mid - 1;
        else start = mid + 1;
    }

    return std::numeric_limits<int>::max();
}

int main()
{
    vector<int> v;
    v.reserve(1'000);
    generate_n(back_inserter(v), 1'000, [](){ return uid(dre); });
    sort(v.begin(), v.end());

    const auto val = 20;
    auto lb = lower_bound(v.begin(), v.end(), 20);
    auto ub = upper_bound(v.begin(), v.end(), 20);
    cout << "lower_bound " << val << " : " << *lb << " Index of " << distance(v.begin(), lb) << endl;
    cout << "upper_bound " << val << " : " << *ub << " Index of " << distance(v.begin(), ub) << endl;
    cout << "counts : " << distance(lb, ub) << endl;

    for (auto it = lb; it != ub; ++it) {
        cout << *it << endl;
    }


}







