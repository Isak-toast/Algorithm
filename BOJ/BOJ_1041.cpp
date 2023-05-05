#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

long minOne(const std::vector<long>& dice) { // 아마도 &을 사용해서 복사를 막는다.
    long min = std::numeric_limits<long>::max();
    for (int i = 0; i < 6; i++) {
        min = std::min(min, dice[i]);
    }
    return min;
}

long minTwo(const std::vector<long>& dice) {
    long min = std::numeric_limits<long>::max(); // LONG.MAX_VALUE와 같다
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j != 5) // 선택된 두 면이 마주보는 경우
                min = std::min(min, dice[i] + dice[j]); // Math.min()과 같다
        }
    }
    return min;
}

long minThree(const std::vector<long>& dice) {
    long min = std::numeric_limits<long>::max();
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (i + j != 5) // 선택된 두 면이 마주보는 경우
                for (int k = j + 1; k < 6; k++) {
                    if (j + k != 5 && k + i != 5) // 나머지도 마주보지 않는 경우
                        min = std::min(min, dice[i] + dice[j] + dice[k]);
                }
        }
    }
    return min;
}

long diceOne(const std::vector<long>& dice) {
    long sum = 0;
    long max = 0;
    for (int i = 0; i < 6; i++) {
        sum += dice[i];
        max = std::max(max, dice[i]);
    }
    return sum - max;
}

int main() {
    long N;
    std::cin >> N;

    std::vector<long> dice(6);
    for (int i = 0; i < 6; i++) {
        std::cin >> dice[i]; // Java는 BufferedReader,StringTokenizer를 사용해야 한다.
    }

    long one = (N - 2) * (5 * N - 6) * minOne(dice);
    long two = 4 * (2 * N - 3) * minTwo(dice);
    long three = 4 * minThree(dice);

    if (N == 1) {
        std::cout << diceOne(dice) << std::endl;
    } else {
        std::cout << one + two + three << std::endl;
    }

    return 0;
}
