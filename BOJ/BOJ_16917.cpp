#include <iostream>
using namespace std;
/*
X, Y의 최소 비용 구하기
*/
int main(){
    int fri, season, half, x, y;
    cin >> season >> fri >> half >> x >> y;

    int ans = 0;
    if(fri+season > 2*half) // 반반이 싸면
    {
        int minV = min(x, y);
        ans += 2*half*minV; // 반반 2개를 사서 메꾼다
        
        ans += min((x-minV)*season, (x-minV)*2*half); // 나머지 양념
        ans += min((y-minV)*fri, (y-minV)*2*half); // 나머지 후라이드
    }
    else {
        ans += x*season;
        ans += y*fri;
    }
    cout << ans;
    return 0;
}