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

	// ���ݰ� ����� ������ ������ ã�ƶ�.
	/*
	* ���� �ΰ� ����� ���� �� ok
	* ���� ��ѵ� ����� ���� �� not ok
	*
	* ���ڴ� �ٸ����� ������ �ϳ��� �׷쿡 ��� ���ԵǾ� �ִ��� Ȯ��
	*
	* ���� �׷��� �ٸ� �׷쿡 ��� ���ԵǸ� -> same_f = true;
	*/
	bool same_f = false;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (Ps[i] != Ps[j]) continue; // ������ �����ϴ�

			// ���̰� ���� ���� �������� ���� ��Ī
			// ��� ���� ���� -> �ϳ��� ���� �ȵǸ� false
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