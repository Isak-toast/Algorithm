#include <iostream>
#include <vector>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

int solution(vector<int>&in_vec, int k, int t);
void func(int cur, int start, int depth, int goal, vector<int>&vec, int sum);

/*
순열과 조합 -> 경우의 수를 구할 때, 조합인지 순열인지 판단을 잘해야한다.

또한 고를 수 있는 숫자에 변동이 있는 것도 고려 -> 목표 k가 변하는 것을 반복

백트래킹과 이상값 변동 조합 문제라고 하자.

arr는 1~15이기에 작음 arr[15]으로 시작 가능 -> k는 반복을 진행할 수 있을 정도로 작다.
t는 백만 이하의 작은 값 -> 오버플로 걱정 없음
*/
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//vector<int> input{2, 5, 3, 8, 1};
	//vector<int> input{1, 1, 2, 2};
	vector<int> input{1, 2, 3, 2};
	int k = 2;
	int t = 2;

	cout << solution(input, k, t);

	return 0;
}

int cnt = 0;
int solution(vector<int>& in_vec, int k, int t) 
{
	int answer = 0;

	for (int i = k; i <= in_vec.size(); i++) {
		func(0, 0, i, t, in_vec, 0);
	}
	answer = cnt;
	return answer;
}

void func(int cur, int start, int depth, int goal, vector<int>& vec, int sum)
{
	if (cur == depth) {
		if (sum <= goal) cnt++;
		return;
	}

	if (sum > goal) return;

	for (int i = start; i < vec.size(); i++) {
		func(cur + 1, i+1, depth, goal, vec, sum + vec[i]);
	}
}