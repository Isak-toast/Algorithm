#include <iostream>
#include <set>
using namespace std;

/*
로마 숫자 표기 4가지 중 몇개를 선택해서 경우의 수를 만드는가!

- 중복된 숫자는 경우의 수에 포함하지 않는다.
- 4개 중 N개를 뽑아서 경우의 수를 세기

-> 시간 초과
*/
set<int> s;

int roma_num[4] = {1, 5, 10, 50};
int ans = 0;
void perm(int cur, int depth, int sum){
    if(cur == depth){
        // set을 사용하지 않고 방문배열을 사용하자.	static int[] visited=new int[10001]; // 수의 합의 중복을 체크하는 배열
        s.insert(sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        perm(cur + 1, depth, sum + roma_num[i]);
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    // vector<int> roma;
    // perm(0, N, roma);
    perm(0, N, 0);
    cout << ans << " " << s.size();
    return 0;
}

