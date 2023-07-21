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

18칸 -> 15 -> 중 경우의 수 78 발견

9^18 -> 

vec에서 find로 동일하게 추측하고 있는 값들만 남긴다.

기존 그룹이 있고 새로운 그룹의 교집합 -> 기존 벡터 이전
- 기존 벡터의 size==1이 될 때까지 추측 쿼리를 던진다.

자릿수 더하기를 해서 반환값이 입력

15 + 3 = 18 -> 9

9 탐색 -> 3을 주고 9 -> 1111 -> 18 도 했는데 

처음이라는 표시..? 

기존 vec를 만들어 숫자값을 저장
현재 vec를 만들어 

1111113 -3 -> 111110 교집합

sum만 찾는게 아니라 전체 숫자를 찾아야 하는건데..?
*/

long long n, a;
vector<vector<int>> preVec;
vector<vector<int>> vec;
/*
어차피 자릿수는 재귀형태로 가능하다.

마찬가지로 백트래킹을 활용해서 sum이 x+a인 경우를 생각하면 되지 않을까
*/
void solution(int cur, int dest, vector<int> &digits, long long sum) {
	if (cur == dest) {
		// n과 동일한 숫자 조합
		if (sum == n) {
			sum -= a; // 원래 x로 돌아가기
			vec.push_back(digits); // 현재 추측 배열
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		// 중간에 값이 넘어버리면 안됨
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
	a = 0; // 다른 숫자를 지속적으로 입력
	
	// 반환값을 받기 위해서
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
			intersection(); // preVec에 교집합 내용이 할당된다.
			
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

