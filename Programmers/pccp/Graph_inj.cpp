#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
인접 리스트 상황이 안됨
-> 인덱스가 아니라 값이 되어야 한다. 생각하고 있는건
injVec[1][3] -> 이건 인접행렬이다.

인접 리스트는 그냥 v 정점에서 iteration 돌면서 인접 리스트를 가져오지 인덱스를 활용하지 못함.

인접행렬로 변경, 다 돌지만 중간 다리를 끊기 위해서는 꼭 필요하다.
*/
int splitVal(int n, int start, int end, vector<vector<int>> injVec)
{
    queue<int> que;
    que.push(start);
    vector<bool> visit(n + 1, false);

    // 다리 끊기
    injVec[start][end] = 0;
    injVec[end][start] = 0;

    int k = 1;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        visit[cur] = true;
        for (int i = 1; i <= n; i++)
        {
            if (injVec[cur][i] && !visit[i])
            {
                que.push(i);
                k++;
            }
        }
    }

    return abs(n - k - k);
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 987654321;
    vector<vector<int>> injVec(n + 1, vector<int>(n + 1)); // nxn 행렬 초기화하는 구문! (기억해라)

    for (int i = 0; i < wires.size(); i++)
    {
        int from = wires[i][0];
        int to = wires[i][1];

        injVec[from][to] = 1;
        injVec[to][from] = 1;
    }

    for (int i = 0; i < wires.size(); i++)
    {
        answer = min(answer, splitVal(n, wires[i][0], wires[i][1], injVec));
    }
    return answer;
}