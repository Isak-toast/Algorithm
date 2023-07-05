#include <stdio.h>
#define min(a, b) (a < b ? a : b)
int a, b, c, x, y, p;
int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	p = a * x + b * y; // 1마리 당 구매했을 때 총 가격
	b = p + (c * 2 - a - b) * min(x, y); // 공통 개수만큼 더하기
	c *= (2 * (x + y - min(x, y))); // 반반으로 구매했을 때 가격
	printf("%d", min(p, min(b, c))); // 3가지 케이스 중 가장 저렴한 것
}
