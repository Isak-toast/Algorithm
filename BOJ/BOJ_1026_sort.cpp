#include <iostream>
#include <vector>
#include <algorithm>
/*
표준 C에서 제공하는 qsort가 아닌 C++에서 제공하는 sort를 사용하기

벡터 정렬은
std::sort(vector.begin(), vector.end())를 사용하면 오름차순 정렬이 된다.
또는
std::reverse(vector.begin(), vector.end())를 사용하면 내림차순 정렬이 된다.

std::sort(vector.begin(), vector.end(), std::greater<int>())를 사용하면 내림차순 정렬이 된다.
또는
std::sort(vector.begin(), vector.end(), std::less<int>())를 사용하면 오름차순 정렬이 된다.

일반 배열 정렬은
std::sort(array, array + size)를 사용하면 오름차순 정렬이 된다. -> array는 배열의 시작 주소를 의미한다. array + size는 배열의 끝 주소를 의미한다.
또는
std::reverse(array, array + size)를 사용하면 내림차순 정렬이 된다.
*/
int main() {
    int N, sum = 0;
    std::cin >> N;

    std::vector<int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    // std::sort를 사용하여 오름차순 정렬
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // 벡터 a를 거꾸로 정렬하고 벡터 b를 정렬하면 최솟값이 된다.
    for (int i = 0; i < N; i++) {
        sum += a[N - i - 1] * b[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
