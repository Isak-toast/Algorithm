#include <bits/stdc++.h>
#include <unordered_set> // 처음에는 unordered_set으로 진행했는데, includes에서 정렬된 벡터를 필요로한다. 
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int N, M;
vector<int> Ps;
vector<int> Cs;
vector<set<int>> Fs(N);

void printVec(const vector<set<int>>&vec, int n) {
	for (int a : vec[n]) {
		cout << a << endl;
	}
}

bool isSuperset(const set<int>& set1, const set<int>& set2) {
	return includes(set1.begin(), set1.end(), set2.begin(), set2.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int p, c;
		cin >> p >> c;
		Ps.push_back(p);
		Cs.push_back(c);
		Fs.push_back(set<int>()); // vector 2���� �ʱ�ȭ
		for (int j = 0; j < c; j++) {
			int f;
			cin >> f;
			Fs[i].insert(f);
		}
	}
	bool ans = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans |= Ps[i] >= Ps[j] && isSuperset(Fs[j], Fs[i]) && (Ps[i] > Ps[j] || Fs[i].size() < Fs[j].size());
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}