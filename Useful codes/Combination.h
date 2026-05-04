//
// Created by SeungUk Lee on 26. 3. 23..
//

#ifndef C___COMBINATION_H
#define C___COMBINATION_H
#include <vector>

template<typename T>
inline std::vector<std::vector<T>> combination(std::vector<T>& lst, int n)
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
            std::vector<T> slice(lst.begin() + i + 1, lst.end());
            for (std::vector<T> temp : combination(slice, n - 1)) {
                std::vector<T> temp2 = { lst[i] };
                temp2.insert(temp2.end(), temp.begin(), temp.end());
                ret.push_back(temp2);
            }
        }
    }

    return ret;
}

#endif //C___COMBINATION_H