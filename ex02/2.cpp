#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int P; cin >> P;
    for (int i = 0; i < P; ++i) {
        int R, C; cin >> R >> C;
        vector<vector<char>> v(R, vector<char>(C, '.'));
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                cin >> v[r][c];
            }
        }

        int max_length = min(R, C);   // 가능한 최대 크기
        if (max_length < 3) { // 3보다 작으면 눈송이를 못만듬
            cout << 0;
            continue;
        }

        int max_size = (max_length - 1) / 2;
        for (int i = 1; i <= max_size; ++i) {
            int size = (i * 2) + 1;

            // 확인용 눈송이 만들기
            vector<vector<char>> check(size, vector<char>(size, '.'));
            for (int r = 0; r < size; ++r) {
                for (int c = 0; c < size; ++c) {
                    if (r == c) check[r][c] = '\\';
                    if (r == (size - (c + 1))) check[r][c] = '/';
                    if (c == size / 2) check[r][c] = '|';
                    if (r == size / 2) {
                        if (check[r][c] == '|') check[r][c] = '+';
                        else check[r][c] = '-';
                    }
                }
            }

            // 확인용 눈송이를 대보면서 확인
            int mR = R / size;
            int mC = C / size;
            int min_check = min(mR, mC);

            int sr = 0, sc = 0;
            for (int r = 0; r < min_check; ++r) {
                for (int c = 0; c < min_check; ++c) {
                    if (v[r + sr][r + sc] != check[r][c]) {
                        ++sc;
                        continue;
                    }


                }
                ++sr;
            }



        }
    }

}