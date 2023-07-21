#include <bits/stdc++.h>
using namespace std;

/*
이런 문제는 그리디 형식이겠지?

완전탐색 or 그리디

완탐
하나씩 준다 -> 솔루션이 완성되는 것을 보고 제출

그리디
기준을 통해서 준다 -> 아마도 끝나는 날짜를 기준으로?

13
 2 4
  3 4


23 25 -> 23
24 25 -> 24
25 25 -> 25
25 26 -> 26
23 27 -> 27

여기서 백트래킹으로 안되면 돌아가는 식으로 선택하면?

- 라인을 받아서 기준으로 정렬
- 재귀를 돌려서 cur마다 돌며 size에서 하나씩 꺼내 솔루션
  - 중복되면 돌아간다.
- 중복되지 않는 조합을 찾으면 성공

pair는 algorithm에 있고 compare 비교 규칙을 만들어 sort(v.begin(), v.begin(), compare)로 비교

오름차순 비교 기준 : a < b (다음 pair의 원소가 더 커야함)

백트래킹 하나씩 꺼낼 때

vector[cur]의 사이즈를 돌면서 -> int vector[cur]의 first, second를 이용해야 한다.
하나씩 고르면서 값을 넣어서 중복과 k를 체크

배열에 순서가 있음. 순서가 있게 만들려면
- 위치를 저장
- pair<int, pair<int, int>> -> pair 말고 int[3]

위치 저장하기 위해서 pair 중첩은 어렵고 int[3]으로 변경 -> ans 부분까지 변경해야 했음
*/

// vector < pair<int, pair<int, int>> vec;
vector<vector<int>> vec;
int month[32]; // 1~31 해서 k를 넘으면 중복됨
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
		// k를 안 넘어가는 선에서 vector 선언
		if (month[i] >= k) continue; // k를 넘기지 않아야 하니까 크거나 같으면 안됨
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
	vector<pair<int, int>> ans(n); // make_pair없이 n으로 size는 할당가능


	for (int i = 0; i < n; i++) {
		// input vacation trip day
		int fst, scd;
		cin >> fst >> scd;
		vector<int> temp = {i, fst, scd};
		vec.push_back(temp);
	}

	// 백트래킹
	sort(vec.begin(), vec.end(), compare); // 뒤쪽을 기준으로 정렬
	solution(0, n, ans); // 처음과 목표 위치 
	sort(ans.begin(), ans.end()); // 첫번째 원소를 기준으로 정렬?
	for (pair<int, int> v : ans) {
		cout << v.second << endl;
	}
	return 0;
}