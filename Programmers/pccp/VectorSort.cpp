#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
#define VVLOOP(v) for(int i = 0; i < v.size(); i++) VLOOP(v[i]) 


// sort의 조건식 메서드를 만들어서 진행해도 된다.
bool sort_condition(const vector<int>&a, const vector<int>&b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), 
		[](vector<int> a, vector<int> b) { // 여기서는 lamdba condition으로 바로 진행
			return a[1] < b[1];
		});
	
	int x = -30000;
	for (int i = 0; i < routes.size(); i++) {
		// 현재 위치가 첫번째보다 작거나 같고
		if (x <= routes[i][0]) {
			x = routes[i][1]; // 카메라 설치 위치
			answer++;
		}
	}

	// VVLOOP(routes) 아쉽게도 줄바꿈이 안됨
	/*for (int i = 0; i < routes.size(); i++) {
		for (auto it = routes[i].begin(); it != routes[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}*/


	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> routes {
		{-20, -15}, { -14, -5 }, { -18, -13 }, { -5, -3 }
	};
	solution(routes);
	return 0;
}