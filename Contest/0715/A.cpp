#include <bits/stdc++.h>
using namespace std;

int N, P, Q;
vector<int> Ds;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> Q;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		Ds.push_back(a);
	}

	int min_price = *min_element(Ds.begin(), Ds.end());
	if (P < min_price + Q) {
		cout << P;
	}
	else {
		cout << min_price + Q;
	}
}