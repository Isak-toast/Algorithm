#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
/*
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.
*/
const int MAX_CHANNEL = 1000000;

int N, M;
std::vector<bool> broken(10, false); // 0 ~ 9

int is_possible(int c) {
    if (c == 0) {
        return broken[0] ? 0 : 1;   // 0번 채널이 고장났으면 0, 아니면 1
    }

    int len = 0;    // 채널 c의 길이
    while (c > 0) {
        if (broken[c % 10]) {       // c의 가장 마지막 자리수가 고장났으면
            return 0;
        }

        len += 1;
        c /= 10; // 자릿수마다 고장난 버튼이 있는지 확인
    }
    return len;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M; // N: 이동하려는 채널, M: 고장난 버튼 개수
    for (int i = 0; i < M; i++) {
        int temp;
        std::cin >> temp;
        broken[temp] = true; // 고장난 버튼
    }

    int ans = std::abs(N - 100); // +, - 버튼만 눌러서 이동하는 경우
    for (int i = 0; i <= MAX_CHANNEL; i++) { // 0 ~ 500000
        int c = i;
        int len = is_possible(c); // 

        if (len > 0) {
            int press = std::abs(c - N);
            ans = std::min(ans, len + press);
        }
    }

    std::cout << ans << '\n';

    return 0;
}
