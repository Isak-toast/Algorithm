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
    // map counting (string key로 count 특징)
    for (auto s : report) {
        stringstream ss(s);
        string from, to;
        ss >> from;
        ss >> to;

        // 신고자에게 알리기 위해서 set 삽입 -> 여기서 중복을 처리한다.
        int s1 = alarm[from].size();
        alarm[from].insert(to);
        int s2 = alarm[from].size();

        // 중복 신고가 아니면 counting
        if (s1 != s2) singo[to]++;
    }

    // id를 돌면서 알림을 받을 수 있는 인원을 체크
    for (auto i : id_list) {
        // 한 명씩 돌아가며 map에 k를 넘었는지 확인
        // 먼저 누굴 신고했는지 -> 신고한 사람은 k를 넘겼는지
        int sum = 0;
        for (auto s : alarm[i]) {
            if (singo[s] >= k) sum++;
        }
        answer.push_back(sum);
    }
    return answer;
}
