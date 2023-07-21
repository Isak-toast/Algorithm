#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> Ss;
bool visit[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		Ss.push_back(a);
	}

	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		visit[i] = true;
		for (int j = i + 1; j < N; j++) {
			if (visit[j]) continue;
			string temp = Ss[i];
			if (temp == Ss[j]) {
				ans++; // same
				visit[j] = true;
			}
			reverse(temp.begin(), temp.end());
			if (temp == Ss[j]) {
				ans++; // reverse
				visit[j] = true;
			}
		}
	}
	cout << ans;
}