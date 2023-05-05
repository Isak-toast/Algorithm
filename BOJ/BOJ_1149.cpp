#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> colorMap;

int minThree(int x, int y, int z) {
    return std::min(x, std::min(y, z));
}

int main() {
    std::cin >> N;

    colorMap.resize(N + 1, std::vector<int>(3));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> colorMap[i][j];
        }
    }

    for (int i = 2; i <= N; i++) {
        colorMap[i][0] = colorMap[i][0] + std::min(colorMap[i - 1][1], colorMap[i - 1][2]);
        colorMap[i][1] = colorMap[i][1] + std::min(colorMap[i - 1][0], colorMap[i - 1][2]);
        colorMap[i][2] = colorMap[i][2] + std::min(colorMap[i - 1][0], colorMap[i - 1][1]);
    }

    std::cout << minThree(colorMap[N][0], colorMap[N][1], colorMap[N][2]) << std::endl;

    return 0;
}
