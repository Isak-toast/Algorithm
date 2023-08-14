#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

int solution(int n);

/*
처음에는 공약수나 공배수 문제인 줄 알았음
생각해보니 5,3로 표현되는 숫자만 찾으면 된다. 그리디 문제임


*/
int main() {
	int n = 3;

	for (int i = 3; i <= 300; i++) {
		int ans = solution(i);
		cout << i << ": " << (ans == 0 ? -1 : ans) << endl;
	}

	return 0;
}

int solution(int n) {
	int answer = 0;
	
	while (n % 5 != 0 && n >= 0) {
		n -= 3;
		answer++;
	}
	if (n > 0) {
		int q = n / 5;
		answer += q;
	}
	else if (n < 0){
		answer = 0;
	}

	return answer;
}