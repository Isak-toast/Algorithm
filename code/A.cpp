#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <cmath>
using namespace std;

#define VLOOP(x) for(auto it = x.begin(); it != x.end(); it++) cout << *it << " ";
#define VVLOOP(v) for(auto y = 0; y < v.size(); y++) for(auto it = v[y].begin(); it != v[y].end(); it++) cout << *it << " "; cout << endl;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	set<string> nodup_gems;
	copy(gems.begin(), gems.end(), inserter(nodup_gems, nodup_gems.end())); // convert vector to set
	
	// two pointer
	int k = nodup_gems.size();
	int i = 0, j = 0;
	map<string, int> jew_map;
	
	jew_map[gems[j]]++;

	/*
	���ڿ��� ���ؼ� �ؽ��Ͽ� �ʿ� �� �ε���ó�� Ű �������� ã���� �Ѵ� -> Map

	���⼭�� �����Ͱ� ������Ű�� �ȵǰ� ���� ��ġ�� ���� �� ������ �ִٰ� �ű�°� �´�.

	- ������ �������� ���� �� ���� j ��ġ�� �̵��ϰ� ������ ����
	- ������ �����ϸ� ���� i ��ġ�� �������� �Ÿ��� ���� -> �������� ���� ������ i�� ����
	
	
	�ð����� ���簪���� �����Ѵ�.
	*/
	int len = gems.size() + 1; // �ּ� �Ÿ�
	int l = i+1, r = j+1;
	while (true) {
		if (jew_map.size() >= k) { // 
			jew_map[gems[i]]--;
			if (len > (j - i)) {
				len = j - i;
				l = i + 1;
				r = j + 1;
			}
			if (jew_map[gems[i]] == 0) jew_map.erase(gems[i]);
			i++;
		}
		else {
			j++;
			if (j >= gems.size()) break;
			jew_map[gems[j]]++;
			if (jew_map.size() >= k) {
				if (len > (j)) {
					len = j - i;
					l = i + 1;
					r = j + 1;
				}
			}
		}
	}
	answer.push_back(l);
	answer.push_back(r);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> gems { "AA", "AA", "AA", "AB", "AC" };
	vector<int> ans = solution(gems);

	VLOOP(ans);
	/*VLOOP(gems);
	VVLOOP(gems);*/
}	