#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k);

int main() {
    vector<string> report { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    vector<string> id_list {"muzi", "frodo", "apeach", "neo"};
    vector<int> ret = solution(id_list, report, 2);
    
    for (auto i : ret) cout << i << " ";
    
    return 0;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> singo;
    map<string, set<string>> alarm;
    // map counting (string key�� count Ư¡)
    for (auto s : report) {
        stringstream ss(s);
        string from, to;
        ss >> from;
        ss >> to;

        // �Ű��ڿ��� �˸��� ���ؼ� set ����
        int s1 = alarm[from].size();
        alarm[from].insert(to);
        int s2 = alarm[from].size();

        // counting
        if (s1 != s2) singo[to]++;
    }

    // id�� ���鼭 �˸��� ���� �� �ִ� �ο��� üũ
    for (auto i : id_list) {
        // �� �� ���ư��� map�� k�� �Ѿ����� Ȯ��
        // ���� ���� �Ű��ߴ��� -> �Ű��� ����� k�� �Ѱ����
        int sum = 0;
        for (auto s : alarm[i]) {
            if (singo[s] >= k) sum++;
        }
        answer.push_back(sum);
    }
    return answer;
}
