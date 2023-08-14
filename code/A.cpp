#include <iostream>
#include <vector>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

int solution(vector<int>&in_vec, int k, int t);
void func(int cur, int start, int depth, int goal, vector<int>&vec, int sum);

/*
������ ���� -> ����� ���� ���� ��, �������� �������� �Ǵ��� ���ؾ��Ѵ�.

���� �� �� �ִ� ���ڿ� ������ �ִ� �͵� ��� -> ��ǥ k�� ���ϴ� ���� �ݺ�

��Ʈ��ŷ�� �̻� ���� ���� ������� ����.

arr�� 1~15�̱⿡ ���� arr[15]���� ���� ���� -> k�� �ݺ��� ������ �� ���� ������ �۴�.
t�� �鸸 ������ ���� �� -> �����÷� ���� ����
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