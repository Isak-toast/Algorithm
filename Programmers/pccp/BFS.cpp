#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int s, int e)
{
	queue<int> que;
	que.push(s);
	vector<int> d{1, -1, 5};

	int k = 0;
	if (s == e)
		return k;
	else
	{
		while (!que.empty())
		{
			int size = que.size();
			k++;
			while (size-- > 0)
			{
				int cur = que.front(); // visit를 사용해서 하면 중복을 막을 수 있다.
				que.pop();
				for (int i = 0; i < 3; i++)
				{
					int nc = cur + d[i];
					que.push(nc);
					if (nc == e)
						return k;
				}
			}
		}
	}
	return k;
}

int main()
{
	int s = 5, e = 14;
	cout << solution(s, e);
	return 0;
}