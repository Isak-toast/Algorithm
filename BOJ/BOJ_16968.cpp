#include <iostream>
using namespace std;

/*
가능한 차량 번호판의 개수를 출력


*/
int ans = 0;

void solution(int cur, int len, string number_plate){
    if(cur == len){
        ans++;
        return; 
    }

    switch(number_plate[cur]){
        case 'c':
            for(char i = 'a'; i <= 'z'; i++){
                // 이전값과 동일하면 안됨 진행
                if(cur > 0 && number_plate[cur-1] == i) continue;
                number_plate[cur] = i;
                solution(cur + 1, len, number_plate);
            }
            break;
        case 'd':
            for(int i = 0; i < 10; i++){
                // 이전값과 동일하면 안됨 진행
                if(cur > 0 && number_plate[cur-1] == i) continue;
                number_plate[cur] = i;
                solution(cur + 1, len, number_plate);
            }
            break;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string number_plate;
    cin >> number_plate;
    // 재귀
    solution(0, number_plate.length(), number_plate);

    cout << ans;
    return 0;
}