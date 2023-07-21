#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> vec
	{
		{0}, {2}, {1,3}, {2},
		{5}, {4, 6}, {5},
		{8}, {7, 9}, {8}
	};
		/*{
			{0, 0, 0, 0}, {0, 2, 4, 0}, { 0,1,3,5}, { 0,0,6,2 },
							{1,5,7,0}, {2,6,8,4}, {3,0,9,5},
							{4,8,0,0}, {5,9,0,7}, {6,0,0,8} 
		};*/
	
	int a, b;
	cin >> a >> b;

	if (find(vec[a].begin(), vec[a].end(), b) != vec[a].end())
		cout << "Yes";
	else
		cout << "No";
	return 0;
}