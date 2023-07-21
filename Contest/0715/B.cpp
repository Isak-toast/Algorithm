#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> Ps;
vector<int> Cs;
vector<vector<int>> Fs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int p, c;
		cin >> p >> c;
		Ps.push_back(p);
		Cs.push_back(c);
		Fs.push_back(vector<int>());
		for (int j = 0; j < c; j++) {
			int f;
			cin >> f;
			Fs[i].push_back(f);
		}
	}

	// 가격과 기능이 동일한 물건을 찾아라.
	/*
	* 값은 싸고 기능이 적은 건 ok
	* 값은 비싼데 기능이 적은 건 not ok
	*
	* 숫자는 다르지만 내용이 하나의 그룹에 모두 포함되어 있는지 확인
	*
	* 작은 그룹이 다른 그룹에 모두 포함되면 -> same_f = true;
	*/
	bool same_f = false;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (Ps[i] != Ps[j]) continue; // 가격이 동일하다

			// 길이가 작은 것을 기준으로 패턴 매칭
			// 모든 조건 만족 -> 하나라도 조건 안되면 false
			if (Cs[i] < Cs[j]) {
				bool cond = true;
				for (int a = 0; a < Cs[i]; a++) {
					auto it = find(Fs[j].begin(), Fs[j].end(), Fs[i][a]);
					if (it == Fs[j].end()) cond = false;
				}
				if (cond) same_f = true;
			}
			if (same_f) break;
		}
		if (same_f) break;
	}

	if (!same_f) cout << "yes";
	else cout << "no";
}