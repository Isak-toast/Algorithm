#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/*
순진하게 모든 string을 비교로 풀이하려고 한다면 시간 복잡도는 증가한다.
여기서는 균형 이진 트리의 중복을 피하는 자료구조를 사용해야 한다.

결국 string이 뒤집거나 동일한 것은 필요없고 중복이 없는 순수한 애들만 있으면 되는 문제..
*/
int main(void){
    int n;
    cin >> n;

    int ans = 0; set<string> T; string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(T.count(s) == 0) ans++; // 입력 string이 현재 이진 트리에 없으면 증가
        T.insert(s);
        reverse(s.begin(), s.end());
        T.insert(s);
    }
    cout << ans << endl;

    return 0;
}