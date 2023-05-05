#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

int main() {
    std::string X, Y;
    std::cin >> X >> Y;

    int ans = std::numeric_limits<int>::max();
    for (std::size_t i = 0; i <= Y.length() - X.length(); ++i) {
        int cnt = 0;
        for (std::size_t j = 0; j < X.length(); ++j) {
            if (X[j] == Y[i + j])
                cnt++;
        }
        ans = std::min(ans, static_cast<int>(X.length()) - cnt);
    }
    std::cout << ans << std::endl;

    return 0;
}
