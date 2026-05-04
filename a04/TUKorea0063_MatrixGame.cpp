// [2021 예선 B] 행렬 게임
// Description
//
// 행렬을 이용하여 여러가지 변경된 행렬을 구성하려고 한다.
// 우선 표준 입력으로 A, B을 입력받고A행 B열 행렬 M을 구성한 후, M행렬을 오른쪽 회전한 행렬 R, 왼쪽 회전한 행렬 L, 전치행렬 T를 각각 구해서 표준 출력한다.
// 예시로 A=3, B=5를 입력받는다.
//
// 3 5
//
// 그런후A행 B열 행렬 M를 구성한다. 행렬 M의 원소는 1행1열, 1행2열, 1행3열 순으로 1부터 차례로 증가한다.
//
// M
// 1  2  3  4  5
// 6  7  8  9  10
// 11  12  13  14  15
//
// 그런후 행렬 M을오른쪽 회전한 B행A열 행렬 R를 구성해서 다음 그림과 같이 표준 출력 한다.
//
// R
// 11  6  1
// 12  7  2
// 13  8  3
// 14  9  4
// 15  10  5
//
// 그런후 행렬 M을왼쪽 회전한B행A열행렬 L을 구성해서 다음 그림과 같이 표준 출력 한다.
//
// L
// 5  10  15
// 4  9  14
// 3  8  13
// 2  7  12
// 1  6  11
//
// 그런후 행렬 M의전치(Transpose)한B행A열행렬 T를 구성해서 다음 그림과 같이 표준 출력 한다.
//
// T
// 1  6  11
// 2  7  12
// 3  8  13
// 4  9  14
// 5  10  15
//
// Input
//
// 첫번째 줄에 자연수 A, B 표준 입력 (1<=A,B<=20)
//
// Output
//
// 알파벳 대문자 'M'을 표준출력하고 다음 줄부터 A행B열 행렬 M을 표준출력한다.
// 알파벳 대문자 'R'을 표준출력하고 다음 줄부터행렬 M을 오른쪽 회전한B행A열 행렬 R를 표준출력한다.
// 알파벳 대문자 'L'을 표준출력하고 다음 줄부터행렬 M을 왼쪽 회전한B행A열 행렬 L를 표준출력한다.
// 알파벳 대문자 'T'을 표준출력하고 다음 줄부터행렬 M의 전치 행렬B행A열 행렬 T를 표준출력한다.
// (주의: 출력 라인 처음과 끝에 공란이 없어야 하며, 숫자와 숫자 사이에는 공란 1개만 띄우도록 표준 출력합니다.)


#include <iostream>
#include <vector>

using namespace std;

void Print(char c, const vector<vector<int>> v)
{
    cout << c << endl;;
    for (int r = 0; r < v.size(); ++r) {
        for (int c = 0; c < v[0].size(); ++c) {
            cout << v[r][c];
            (c != v[0].size() - 1) ? cout << ' ' : cout << '\n';
        }
    }
}

int main()
{
    int A, B;
    cin >> A >> B;

    vector<vector<int>> M(A, vector<int>(B, 0));
    vector<vector<int>> Modified(B, vector<int>(A, 0));

    int cnt = 0;
    for (int r = 0; r < A; ++r) {
        for (int c = 0; c < B; ++c) {
            M[r][c] = ++cnt;
        }
    }


    Print('M', M);

    for (int r = 0; r < A; ++r) {
        for (int c = 0; c < B; ++c) {
            int nr = A - r - 1;
            int nc = c;
            int tr = c;
            int tc = r;
            Modified[tr][tc] = M[nr][nc];
        }
    }

    Print('R', Modified);


    for (int r = 0; r < A; ++r) {
        for (int c = 0; c < B; ++c) {
            int nr = r;
            int nc = B - c - 1;
            int tr = c;
            int tc = r;
            Modified[tr][tc] = M[nr][nc];
        }
    }

    Print('L', Modified);

    for (int r = 0; r < A; ++r) {
        for (int c = 0; c < B; ++c) {
            int nr = r;
            int nc = c;
            int tr = c;
            int tc = r;
            Modified[tr][tc] = M[nr][nc];
        }
    }


    Print('T', Modified);

}

