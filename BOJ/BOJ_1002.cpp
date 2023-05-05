#include <iostream>

using namespace std;
/*

https://travelerfootprint.tistory.com/61


x1, y1, r1은 첫 번째 원의 중심 좌표와 반지름
x2, y2, r2는 두 번째 원의 중심 좌표와 반지름

원이 내접한 경우 |r2 - r1| = d
원이 외접한 경우 r1 + r2 = d

원이 두 점에서 만나는 경우 r1 + r2 > d > |r1 - r2|
원이 한 점에서 만나는 경우 r1 + r2 = d
원이 만나지 않는 경우 r1 + r2 < d 또는 d < |r1 - r2|


if distance == 0 and r1 == r2 :  # 두 원이 동심원이고 반지름이 같을 때
    print(-1)
elif abs(r1-r2) == distance or r1 + r2 == distance:  # 내접, 외접일 때
    print(1)
elif abs(r1-r2) < distance < (r1+r2) :  # 두 원이 서로다른 두 점에서 만날 때
    print(2)
else:
    print(0)  # 그 외에

*/
int main() {
    int t, x1, y1, r1, x2, y2, r2;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // 두 원의 중심 사이의 거리
        int sum_r = (r1 + r2) * (r1 + r2); // 반지름의 합의 제곱
        int sub_r = (r1 - r2) * (r1 - r2); // 반지름의 차의 제곱

        if (distance == 0 && r1 == r2) { // 두 원이 동심원이고 반지름이 같을 때
            printf("-1\n");
        } else if (sub_r == distance || sum_r == distance) { // 내접, 외접일 때
            printf("1\n");
        } else if (sub_r < distance && distance < sum_r) { // 두 원이 서로다른 두 점에서 만날 때
            printf("2\n");
        } else { // 그 외에
            printf("0\n");
        }
    }
    return 0;
}