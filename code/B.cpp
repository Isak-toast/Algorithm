#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
#define VVLOOP(v) for(int i = 0; i < v.size(); i++) VLOOP(v[i])

vector<vector<int>> solution(vector<vector<int>> routes, int val_etx) {
	vector<vector<int>> answer;

	// val_etx 비교를 통해서 원하는 vector를 삽입 후 sorting
	for (int i = 0; i < routes.size(); i++)
	{
		vector<int> vec = routes[i];
		if (routes[i][1] < val_etx) {
			answer.push_back(vec);
		}
	}
	VVLOOP(answer);

	sort(answer.begin(), answer.end(), 
		[](vector<int>& a, vector<int>& b) {
		return a[2] > b[2];
	});
	VVLOOP(answer);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> routes {
		{-20, 20230501, -15}, { -14, 20230412, -5 }, { -18, 20230701, -13 }, { -5, 20220912, -3 }
	};
	int val_etx = 20230601;
	solution(routes, val_etx);
	return 0;
}