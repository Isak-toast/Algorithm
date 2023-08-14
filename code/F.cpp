#include <string>
#include <vector>
using namespace std;


int ans = 0;
void dfs(int cur, int k, int n, vector<bool>& visit, vector<vector<int>>& dun) {
    if (cur == n) {
        ans = max(ans, cur);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        visit[i] = true;

        // 최소 피로도 <= k and k - 소진 피로드 >= 0
        if (k >= dun[i][0] && k - dun[i][1] >= 0) {
            dfs(cur + 1, k - dun[i][1], n, visit, dun);
        }
        ans = max(ans, cur);
        visit[i] = false;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visit(dungeons.size(), false);
    dfs(0, k, dungeons.size(), visit, dungeons);
    answer = ans;
    return answer;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons{ {80, 20}, { 50, 40 }, { 30, 10 } };
    solution(k, dungeons);
    return 0;
}