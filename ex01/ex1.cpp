#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    int N; cin >> N;
    vector<char> seats;
    copy_n(istream_iterator<char>{cin}, N, back_inserter(seats));

    int nSeats = 0;
    int nCups = 0;

    for (int i = 0; i < N; ++i) {
        if (seats[i] == 'S') nSeats++;
        if (seats[i] == 'L') {
            if (seats[i+1] == 'L') {
                nSeats++;
                i++;
            }
        }

        nCups++;
    }
    nCups += 1; // 맨앞자리

    cout << max(nSeats, nCups);


}