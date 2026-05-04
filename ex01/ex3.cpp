#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

class Submission {
public:
    int sub = 0;
    int bossRank = 0;
    int votes = 0;
    int score = 0;
};

int main()
{
    int n; cin >> n;
    vector<Submission> subs(n);
    for (int i = 0; i < n; ++i) {
        int r; cin >> r;    // r : i 랭킹에 제출의 번호
        subs[r-1].bossRank = i + 1;  // 회장 랭킹 저장
        subs[r-1].sub = r;
    }

    for (int i = 0; i < n; ++i) {
        int v; cin >> v;    // v : sub[i] 의 투표수
        subs[i].votes = v;
    }

    // 투표수순 정렬
    sort(subs.begin(), subs.end(), [](const Submission& lhs, const Submission& rhs) {
        return lhs.votes > rhs.votes;
    });

    // 점수 매김
    // 회장점수 : N - 랭킹 - 1
    // 투표점수 : 정렬 후 순서대로 N에서 감소
    int curScore = n;
    for (auto& s : subs) {
        s.score = (n - (s.bossRank - 1)) + curScore--;
    }

    sort(subs.begin(), subs.end(), [](const Submission& lhs, const Submission& rhs) {
        if (lhs.score > rhs.score) return true;
        else if (lhs.score == rhs.score) {
                return lhs.votes > rhs.votes;
        }
        return false;
    });

    for (int i = 0; i < n; ++i) {
        cout << i+1 << ". Kod";
        if (subs[i].sub <= 9) cout << 0 << subs[i].sub;
        else cout << subs[i].sub;
        cout << " (" << subs[i].score << ')' << endl;
    }

}
