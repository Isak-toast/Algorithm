#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
���� ����Ʈ ��Ȳ�� �ȵ�
-> �ε����� �ƴ϶� ���� �Ǿ�� �Ѵ�. �����ϰ� �ִ°�
injVec[1][3] -> �̰� ��������̴�. 

���� ����Ʈ�� �׳� v �������� iteration ���鼭 ���� ����Ʈ�� �������� �ε����� Ȱ������ ����.

������ķ� ����, �� ������ �߰� �ٸ��� ���� ���ؼ��� �� �ʿ��ϴ�.
*/
int splitVal(int n, int start, int end, vector<vector<int>> injVec) {
    queue<int> que;
    que.push(start);
    vector<bool> visit(n + 1, false);

    // �ٸ� ����
    injVec[start][end] = 0;
    injVec[end][start] = 0;

    int k = 1;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        visit[cur] = true;
        for (int i = 1; i <= n; i++) {
            if (injVec[cur][i] && !visit[i]) {
                que.push(i);
                k++;
            }
        }
    }
 
    return abs(n-k - k);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    vector<vector<int>> injVec(n + 1, vector<int>(n+1)); // nxn ��� �ʱ�ȭ�ϴ� ����! (����ض�)

    for (int i = 0; i < wires.size(); i++) {
        int from = wires[i][0];
        int to = wires[i][1];

        injVec[from][to] = 1;
        injVec[to][from] = 1;
    }

    for (int i = 0; i < wires.size(); i++) {
        answer = min(answer, splitVal(n, wires[i][0], wires[i][1], injVec));
    }
    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> wires{{1, 3}, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 4, 6 }, { 4, 7 }, { 7, 8 }, { 7, 9 }};
    cout << solution(n, wires);
    return 0;
}