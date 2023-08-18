#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define VLOOP(v) for(auto it = v.begin(); it != v.end() ; it++) cout << *it << " ";
/*
1234 5678 9101112 13141516 -> 1,2,3,4 �������� �����ؼ� ���������� searching

Binary Tree Search�� Ȯ�� ����? + Divide ������ �Բ� ���Եȴ�.

1. ���� 0, 3 -> ��� ����ȴ�. -> ���������� 0, 3 ������ ��� ����
2. 1,2 ������ ��������� Ǯ��
3. ���� ������ ������ �� -> x �� 1�� �Ǿ��� �� ����
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
            // ���ʿ� 4^(n-2), R/4^(n-2), R%4^(n-2)
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