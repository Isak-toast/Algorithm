#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/*
알파벳 순서로 출력이 진행

2회 이상 나타난 알파벳이 2개 이상의 부분으로 나뉘어 있다!
연속이 아닌 알파벳을 2개 이상 경우를 찾으라

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