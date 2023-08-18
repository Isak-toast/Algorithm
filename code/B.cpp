#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/*
���ĺ� ������ ����� ����

2ȸ �̻� ��Ÿ�� ���ĺ��� 2�� �̻��� �κ����� ������ �ִ�!
������ �ƴ� ���ĺ��� 2�� �̻� ��츦 ã����

*/
string solution(string input_string) {
    string answer = "";
    vector<int> alpha(26);

    int n = input_string.size();
    int j = 0;
    char c = input_string.at(j);
    while (true) {
        j++;
        if (j >= n) {
            alpha[(int)c - 97]++;
            break;
        }

        while (c != input_string.at(j)) {
            alpha[(int)c - 97]++;
            c = input_string.at(j);
        }
    }

    for (int i = 0; i < alpha.size(); i++) {
        if (alpha[i] >= 2)
            answer.push_back(i + 'a');
    }

    return answer.size() == 0 ? "N" : answer;
}

int main() {
    string input = "zbzbz";
    cout << solution(input);
    return 0;
}