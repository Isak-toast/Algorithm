#include <iostream>
#define FOR(a,b) for(int a = 0; a <= b; a++)

/*
숫자를 선택할 수 있는 개수
- 숫자 -> 숫자가 적으면 방문배열 가능
- 다른 기호들과의 합이 n개 특정
*/
int main()
{
    int n, i1, i5, i10, i50;
    int visit[10001]={0,};
    std::cin >> n;
    FOR(i1, n) FOR(i5, n) FOR(i10, n) FOR(i50, n) if(i1+i5+i10+i50 == n) visit[i1 + i5*5 + i10*10 + i50*50] = 1;
    int ans = 0;
    for(int i = 0; i <= 10000; i++) if(visit[i]) ans++;
    std::cout << ans;
    return 0; 
}