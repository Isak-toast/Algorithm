// sliding window
/*
longestWindow

https://www.piratekingdom.com/leetcode/templates/sliding-window
*/
#include <vector>
using namespace std;

bool invalid(int a, int b)
{
    return a < b;
}

int longestWindow(vector<int> &list)
{
    int j = 0, ans = 0;

    for (int i = 0; i < list.size(); i++)
    {

        while (invalid(i, j)) // write invalid condition
        {
            j++;
        }
        ans = max(ans, i - j - 1);
    }
}

int main()
{
    return 0;
}