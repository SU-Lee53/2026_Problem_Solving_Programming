// [2020 본선 A] Postfix 표현식
// Description
//
// +및-연산자를 사용하여a,…z 알파벳 소문자로작성된 산술 표현식을 고려하십시오.다음은 예입니다.
//
// ((a + b)-(((c + d) -e) + a))
// 완전히 괄호로 묶인 표현식은다음과 같은 간단한 규칙을 사용하여postfix라는 다른 형식으로 변환 할 수 있습니다.
//
// 변수는 그대로 유지됩니다.{a,…, z}의모든x에대해Translate [x] = x.
// (E1 +E2)형태의 식은Translate[E1] Translate[E2] + 로 변환된다.
// (E1 - E2)형태의 식은 Translate[E1] Translate[E2] - 로 변환된다.
// 예를 들어, 위의 표현식은 다음과 같이 번역됩니다.
//
//  Translate[((a+b)-(((c+d)-e)+a))]
// = Translate[(a+b)] Translate[(((c+d)-e)+a)] -
// = Translate[a] Translate[b] + Translate[((c+d)-e)] Translate[a] + -
// = a b + Translate[(c+d)] Translate[e] - a + -
// = a b + Translate[c] Translate[d] + e - a + -
// = a b + c d + e - a + -
// 당신의 임무는 이 작업의 반대를 수행하는 것입니다.
//
// 접미사로 표현되는 postfix 표현식을괄호로 잘 묶인원래 표현식으로 재구성해야합니다.
//
//
// Input
// +,-및 문자a, b,…, z가포함된 postfix 표현식을 포함하는 단일 행
// 최대 80 개의 기호가 있습니다.
//
// Output
// 위에서 설명한 번역을 통해 입력postfix 표현식을괄호로 잘 묶인원래 표현식을 출력합니다.
//
// Sample Input 1
// ab+cd+e-a+-
//
// Sample Output 1
// ((a+b)-(((c+d)-e)+a))

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string in;
    cin >> in;
    vector<string> s;
    for (char c : in) {
        if (isalpha(c)) {
            string str{c};
            s.push_back(str);
        }
        else {
            auto b = s.back(); s.pop_back();
            auto a = s.back(); s.pop_back();
            std::string newstr = "(" + a + string{c} + b + ")";
            s.push_back(newstr);
        }
    }

    for (const auto& str : s) {
        cout << str;
    }

}






