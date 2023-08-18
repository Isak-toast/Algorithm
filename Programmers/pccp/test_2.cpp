#include <string>
#include <vector>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

/**
능력치의 최대값을 구하는 경우

학생의 수는 10 -> 10명 중 10개 뽑기

1. 완전탐색 -> 백트래킹(n-queen)
- DFS + 순열 + 방문배열

*/
int answer = 0;
void findMaxGroup(int cur, int dep, int n, int sum, vector<bool> visit, vector<vector<int>> &abi){
    if(cur == dep){ // 종목 개수만큼 추출
        answer = max(answer, sum);
    }
    
    // 전체 사람 중 종목 개수만큼 선택
    for(int i = 0; i < n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        findMaxGroup(cur + 1, dep, n, sum+abi[i][cur], visit, abi);
        visit[i] = false;
    } 
}

int solution(vector<vector<int>> ability) {
    int person = ability.size(); // 사람 수만큼 뽑지 않을 수도 있다.
    int cap = ability[0].size(); // 종목 대표를 뽑는다.
    vector<bool> visit(person); // 선택은 사람만큼 진행
    findMaxGroup(0, cap, person, 0, visit, ability);
    
    return answer;
}