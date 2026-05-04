#include <iostream>
#include <vector>
#include <random>


// Quicksort

using namespace std;

void Quicksort_INL(std::vector<int>& v, int start, int end)
{
    if (start < end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;
    while (left <= right) {
        while(left <= end && v[left] <= v[pivot]){
            left++;
        }
        while (right > start && v[right] >= v[pivot]) {
            right--;
        }
        if (left > right) {
            swap(v[pivot], v[right]);
        }
        else {
            swap(v[left], v[right]);
        }
    }

    Quicksort_INL(v, start, right - 1);
    Quicksort_INL(v, right+1, end);
}

void Quicksort(std::vector<int>& v)
{
    Quicksort_INL(v, 0, v.size() - 1);
}

std::default_random_engine dre{std::random_device{}()};
std::uniform_int_distribution<int> uid(0, 999);

int main()
{
    vector<int> v(100);
    std::generate(v.begin(), v.end(), [](){return uid(dre);});

    for (int n : v) {
        cout << n << ", ";
    }
    cout << endl;


    Quicksort(v);

    for (int n : v) {
        cout << n << ", ";
    }

}


