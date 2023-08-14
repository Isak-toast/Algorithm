#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define VLOOP(v) for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

vector<string> solution(vector<string>& vec);

int main() {
	vector<string> input {"spy", "ray", "spy", "room", "once", "ray", "spy", "once"};

	vector<string> vec = solution(input); // define���� ��ȯ�� vector�� �ٷ� ������� ����

	VLOOP(vec);

	return 0;
}

vector<string> solution(vector<string>& vec) {
	vector<string> answer;

	map<string, int> vec_map;
	for (auto i : vec) {
		vec_map[i]++;
	}

	// map -> vector
	vector<pair<string, int>> sort_vec(vec_map.begin(), vec_map.end());

	// value ���� ����
	sort(sort_vec.begin(), sort_vec.end(),
		[](pair<string, int>& a, pair<string, int>& b) {
		return a.second > b.second;
	});
	for (auto k : sort_vec) {
		answer.push_back(k.first);
	}

	return answer;
}