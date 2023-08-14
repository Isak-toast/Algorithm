#include <iostream>
#include <vector>
using namespace std;

#define VLOOP(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

int dfs(int cur, int depth, int n, vector<int>& v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v;
	dfs(0, k, n, v);

	return 0;
}

int dfs(int cur, int depth, int n, vector<int>& v) {
	if (cur == depth) {
		VLOOP(v);
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		dfs(cur + 1, depth, n, v);
		v.pop_back();
	}

}