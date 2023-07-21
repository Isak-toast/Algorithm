#include <bits/stdc++.h>
using namespace std;

/*
1,000,000,000,000 -> 10^12 / 1,000,000,000 -> 10^9

(x + a) <- query a
(x + b) <- query b

x + 3 -> 25

15 -> (7+5)+3 -> 75
12 -> (1+1+1->) 

300 -> (1*18)

18ĭ -> 15 -> �� ����� �� 78 �߰�

9^18 -> 

vec���� find�� �����ϰ� �����ϰ� �ִ� ���鸸 �����.

���� �׷��� �ְ� ���ο� �׷��� ������ -> ���� ���� ����
- ���� ������ size==1�� �� ������ ���� ������ ������.

�ڸ��� ���ϱ⸦ �ؼ� ��ȯ���� �Է�

15 + 3 = 18 -> 9

9 Ž�� -> 3�� �ְ� 9 -> 1111 -> 18 �� �ߴµ� 

ó���̶�� ǥ��..? 

���� vec�� ����� ���ڰ��� ����
���� vec�� ����� 

1111113 -3 -> 111110 ������

sum�� ã�°� �ƴ϶� ��ü ���ڸ� ã�ƾ� �ϴ°ǵ�..?
*/

long long n, a;
vector<vector<int>> preVec;
vector<vector<int>> vec;
/*
������ �ڸ����� ������·� �����ϴ�.

���������� ��Ʈ��ŷ�� Ȱ���ؼ� sum�� x+a�� ��츦 �����ϸ� ���� ������
*/
void solution(int cur, int dest, vector<int> &digits, long long sum) {
	if (cur == dest) {
		// n�� ������ ���� ����
		if (sum == n) {
			sum -= a; // ���� x�� ���ư���
			vec.push_back(digits); // ���� ���� �迭
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		// �߰��� ���� �Ѿ������ �ȵ�
		if (sum + i > n) continue;
		digits[cur] = i;
		solution(cur + 1, dest, digits, sum + i);
	}
}

void intersection() {
	vector<vector<int>> buff(preVec.size(), vec.size());
	auto iter = set_intersection(preVec.begin(), preVec.end(), vec.begin(), vec.end(), buff.begin());
	buff.erase(iter, buff.end());

	preVec.assign(buff.begin(), buff.end());
	vec.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string empty;
	a = 0; // �ٸ� ���ڸ� ���������� �Է�
	
	// ��ȯ���� �ޱ� ���ؼ�
	while (a <= 1000000000000000000) {
		cout << "query " << a;

		getline(cin, empty);
		cin >> n;
		
		vector<int> digits(18);
		solution(0, 17, digits, 0);
		
		if (preVec.empty()) {
			preVec.assign(vec.begin(), vec.end()); // vector copy
		}
		else {
			// intersection
			intersection(); // preVec�� ������ ������ �Ҵ�ȴ�.
			
		}
		cout << endl;
		if (preVec.size() == 1) break;
		a++;
	}

	cout << "answer ";
	for (auto i = preVec[0].rbegin(); i != preVec[0].rend(); i++) {
		cout << *i << endl;
	}
	return 0;
}

