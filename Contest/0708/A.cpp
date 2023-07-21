#include <bits/stdc++.h>
using namespace std;

/*
�̷� ������ �׸��� �����̰���?

����Ž�� or �׸���

��Ž
�ϳ��� �ش� -> �ַ���� �ϼ��Ǵ� ���� ���� ����

�׸���
������ ���ؼ� �ش� -> �Ƹ��� ������ ��¥�� ��������?

13
 2 4
  3 4


23 25 -> 23
24 25 -> 24
25 25 -> 25
25 26 -> 26
23 27 -> 27

���⼭ ��Ʈ��ŷ���� �ȵǸ� ���ư��� ������ �����ϸ�?

- ������ �޾Ƽ� �������� ����
- ��͸� ������ cur���� ���� size���� �ϳ��� ���� �ַ��
  - �ߺ��Ǹ� ���ư���.
- �ߺ����� �ʴ� ������ ã���� ����

pair�� algorithm�� �ְ� compare �� ��Ģ�� ����� sort(v.begin(), v.begin(), compare)�� ��

�������� �� ���� : a < b (���� pair�� ���Ұ� �� Ŀ����)

��Ʈ��ŷ �ϳ��� ���� ��

vector[cur]�� ����� ���鼭 -> int vector[cur]�� first, second�� �̿��ؾ� �Ѵ�.
�ϳ��� ���鼭 ���� �־ �ߺ��� k�� üũ

�迭�� ������ ����. ������ �ְ� �������
- ��ġ�� ����
- pair<int, pair<int, int>> -> pair ���� int[3]

��ġ �����ϱ� ���ؼ� pair ��ø�� ��ư� int[3]���� ���� -> ans �κб��� �����ؾ� ����
*/

// vector < pair<int, pair<int, int>> vec;
vector<vector<int>> vec;
int month[32]; // 1~31 �ؼ� k�� ������ �ߺ���
int n, k;


/*bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}*/
bool compare(vector<int> a, vector<int> b) {
	if (a[2] == b[2]) {
		return a[1] < b[1];
	}
	else {
		return a[2] < b[2];
	}
}


int solution(int cur, int dest, vector<pair<int, int>> &ans) {
	if (cur == dest) {
		return 1;
	}

	int fst = vec[cur][1];
	int scd = vec[cur][2];

	for (int i = fst; i <= scd; i++) {
		// k�� �� �Ѿ�� ������ vector ����
		if (month[i] >= k) continue; // k�� �ѱ��� �ʾƾ� �ϴϱ� ũ�ų� ������ �ȵ�
		month[i]++;
		ans[cur].first = vec[cur][0];
		ans[cur].second = i;
		if(solution(cur + 1, dest, ans)) return 1;
		month[i]--;
	}

	return 0;
}

int main() {
	cin >> n >> k;
	vector<pair<int, int>> ans(n); // make_pair���� n���� size�� �Ҵ簡��


	for (int i = 0; i < n; i++) {
		// input vacation trip day
		int fst, scd;
		cin >> fst >> scd;
		vector<int> temp = {i, fst, scd};
		vec.push_back(temp);
	}

	// ��Ʈ��ŷ
	sort(vec.begin(), vec.end(), compare); // ������ �������� ����
	solution(0, n, ans); // ó���� ��ǥ ��ġ 
	sort(ans.begin(), ans.end()); // ù��° ���Ҹ� �������� ����?
	for (pair<int, int> v : ans) {
		cout << v.second << endl;
	}
	return 0;
}