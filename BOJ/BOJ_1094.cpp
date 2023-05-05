#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    std::cin >> X;

    int ans = 0;
    int stick = 64;
    int cur = 0;
    while (cur != X) {
        if (stick == X) {
            ans++;
            break;
        }
        stick /= 2;
        // 절반을 잘라서 X보다 크면 붙인다. 붙인 막대 개수만 센다
        if (stick + cur <= X) {
            cur += stick;
            ans++;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
