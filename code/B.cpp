#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
#define VVLOOP(v) for(int i = 0; i < v.size(); i++) VLOOP(v[i]) 


// sort�� ���ǽ� �޼��带 ���� �����ص� �ȴ�.
bool sort_condition(const vector<int>&a, const vector<int>&b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), 
		[](vector<int> a, vector<int> b) { // ���⼭�� lamdba condition���� �ٷ� ����
			return a[1] < b[1];
		});
	
	int x = -30000;
	for (int i = 0; i < routes.size(); i++) {
		// ���� ��ġ�� ù��°���� �۰ų� ����
		if (x <= routes[i][0]) {
			x = routes[i][1]; // ī�޶� ��ġ ��ġ
			answer++;
		}
	}

	// VVLOOP(routes) �ƽ��Ե� �ٹٲ��� �ȵ�
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