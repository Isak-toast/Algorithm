#include <stdio.h>
#include <stdlib.h>

/*
길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.
S = A[0] × B[0] + ... + A[N-1] × B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.
S의 최솟값을 출력하는 프로그램을 작성하시오.

A를 거꾸로 작은 순서부터 정렬해서 B와 곱하면 최솟값이 나온다.

이에 대한 증명은 간단하다.
A를 거꾸로 정렬하면 A[0]이 가장 큰 값이 되고, B를 정렬하면 B[0]이 가장 작은 값이 된다.
그러므로 A[0]×B[0]이 가장 작은 값이 된다.
그 다음으로 A[1]×B[1]이 가장 작은 값이 되는데, A[1]은 A[0]보다 작으므로 B[1]이 B[0]보다 작아야 한다.
그러므로 A[1]×B[1]이 A[1]×B[0]보다 작아진다.
이런 식으로 A[N-1]×B[N-1]이 A[N-1]×B[0]보다 작아지므로 A를 거꾸로 정렬하면 최솟값이 된다.

*/
int Ascending(const void* a, const void* b) {
    return *(int*)a-*(int*)b;
}

int Descending(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}


int main() {
    int i,a[55],b[55],N,sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    for(i=0;i<N;i++) scanf("%d",&b[i]);
    qsort(a,N,sizeof(int),Ascending); // qsort(배열, 배열의 크기, 배열의 원소의 크기, 비교 함수) -> std::algorithm의 sort을 사용하는 것을 권장
    qsort(b,N,sizeof(int),Ascending);
    for(i=0;i<N;i++) sum+=a[N-i-1]*b[i];    // a를 거꾸로 정렬하고 b를 정렬하면 최솟값이 된다.
    printf("%d",sum);
    return 0;
}