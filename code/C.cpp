#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define VLOOP(v) for(auto it = v.begin(); it != v.end() ; it++) cout << *it << " ";
/*
1234 5678 9101112 13141516 -> 1,2,3,4 영역으로 분할해서 지속적으로 searching

Binary Tree Search의 확장 개념? + Divide 개념이 함께 포함된다.

1. 최초 0, 3 -> 결과 보장된다. -> 지속적으로 0, 3 영역은 결과 보장
2. 1,2 영역은 재귀적으로 풀이
3. 종료 시점이 나누는 값 -> x 가 1이 되었을 때 종료
*/

string genLaw(int div, int qou, int rem) {
    if (div == 1) {
        if (qou == 0) return "RR";
        else if (qou == 1 || qou == 2) return "Rr";
        else if (qou == 3) return "rr";
    }

    if (qou == 0) return "RR";
    else if (qou == 1 || qou == 2) {
        div /= 4;
        return genLaw(div, rem / div, rem % div);
    }
    else if (qou == 3) return "rr";
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for (int i = 0; i < queries.size(); i++) {
        int first = queries[i][0];
        int second = queries[i][1];
        if (first == 1 && second == 1)
        {
            answer.push_back("Rr");
        }
        else {
            // 최초에 4^(n-2), R/4^(n-2), R%4^(n-2)
            int div = pow(4, first - 2);
            answer.push_back(genLaw(div, (second - 1) / div, (second - 1) % div));
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> queries{{4, 26}};
    for (string str : solution(queries)) {
        cout << str << endl;
    }
    return 0;
}