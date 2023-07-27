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
	문자열에 대해서 해싱하여 필요 시 인덱스처럼 키 매핑으로 찾도록 한다 -> Map

	여기서는 포인터가 증가시키면 안되고 현재 위치를 받을 때 이전에 있다가 옮기는게 맞다.

	- 보석이 동일하지 않을 때 현재 j 위치를 이동하고 보석을 증가
	- 보석이 동일하면 현재 i 위치의 보석까지 거리를 측정 -> 동일하지 않을 때까지 i를 증가
	
	
	시간축은 현재값으로 진행한다.
	*/
	int len = gems.size() + 1; // 최소 거리
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