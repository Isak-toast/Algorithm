#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;
typedef long long ll;

bool isCon(vector<int>& edge, int from, int to) {
    return find(edge.begin(), edge.end(), to) == edge.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int ans = 0;
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    
    int tomato[200001] = { -1, }; 
    vector<vector<ll>> edge(200001, vector<ll>());
    
    // 양방향 설정
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    // 0일에 익은 토마토
    queue<int> que;
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        tomato[v] = 0;
        que.push(v);
    }

    // 날짜에 따라서 토마토 변경
    vector<vector<int>> date;
    for (int i = 0; i < q; i++) {
        int t, from, to;
        cin >> t >> from >> to;
        date.push_back(vector<int>{t, from, to});
    }

    /*for (int i = 0; i < date.size(); i++) {
        vector<int> vec = date[i];
        for (int j = 0; j < vec.size(); j++) {
            cout << vec[j] << " ";
        }
        cout << endl;
    }*/

    int k = 1;
    while (!que.empty()) {
        int size = que.size();

        while (size > 0) {
            int v = que.front();
            que.pop();
            // 주변 토마토 익어간다.
            for (auto it = edge[v].begin(); it != edge[v].end(); it++) {
                if (tomato[*it] != -1) continue; // 방문배열이자 익은 날짜

                que.push(*it);
                tomato[*it] = k;
            }
            size--;
        }
        // 연결성을 확인해서 연결을 끊거나 혹은 이어주거나
        for (int i = 0; i < date.size(); i++) {
            vector<int> con = date[i];
            if (con[0] != k) continue;
            
            if (isCon(con, con[0], con[1])) {
                edge[con[0]].erase(remove(edge[con[0]].begin(), edge[con[0]].end(), con[1]), edge[con[0]].end());
                edge[con[1]].erase(remove(edge[con[1]].begin(), edge[con[1]].end(), con[0]), edge[con[1]].end());
            }
            else {
                edge[con[0]].push_back(con[1]);
                edge[con[1]].push_back(con[0]);
            }
        }
        k++;
    }
    for (int i = 1; i <= n; i++) {
        cout << tomato[i] << " ";
    }
    return 0;
}