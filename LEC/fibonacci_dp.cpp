#include <iostream>
#include <chrono>
using namespace std::chrono;

long long fibo(long long x)
{
    if (x == 1 || x == 2) return 1;
    return fibo(x-1) + fibo(x-2);
}

template<long long N>
struct fibo_t {
    constexpr static long long value = fibo_t<N-1>::value + fibo_t<N-2>::value;
};

template<>
struct fibo_t<1> {
    constexpr static long long value = 1;
};

template<>
struct fibo_t<2> {
    constexpr static long long value = 1;
};

static long long dpTable[101] = {0,};
//memset(dpTable, 0, sizeof(dpTable));

long long fibo_dp_topdown(long long x)
{
    if (x == 1 || x == 2) return 1;
    if (dpTable[x]) return dpTable[x];
    dpTable[x] = fibo_dp_topdown(x-1) + fibo_dp_topdown(x-2);
    return dpTable[x];
}

long long fibo_dp_bottomup(long long x)
{
    dpTable[1] = dpTable[2] = 1;
    for (int i = 3; i < x+1; ++i) {
        dpTable[i] = dpTable[i-1] + dpTable[i-2];
    }
    return dpTable[x];
}

int main()
{
    auto start = high_resolution_clock::now();

    std::cout << fibo(40) << std::endl;
    //std::cout << fibo_dp_topdown(40) << std::endl;
    //std::cout << fibo_dp_bottomup(40) << std::endl;


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    std::cout << "time spent : " << duration << "ns";

    //std::cout << fibo_t<50>::value << std::endl;

}