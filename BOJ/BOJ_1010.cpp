#include <cstdio>

/*
n과 m을 입력받습니다.
변수 a를 초기화하고, 계산을 수행합니다. 
이 계산은 조합(Combination)을 구하는 공식과 유사해 보입니다: C(m, n) = m! / (n!(m-n)!)

이 공식은 다음과 같이 증명할 수 있습니다:
n개의 원소 중에서 m개의 원소를 순서 없이 뽑는 경우의 수를 nCm이라고 합니다.
이는 n개의 원소 중에서 m개의 원소를 순서 있게 뽑은 후, 그 순서를 없애는 경우의 수와 같습니다.
즉, nPm / m! = nCm이라는 것입니다.

*/
int t, m, n, i, j;
int main() {
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d%d", &n, &m);
        int a = 1;
        for(j = 0; j < n; j++){
            a = a*(m - j) / (j + 1);
        }
        printf("%d\n", a);
    }
    return 0;
}