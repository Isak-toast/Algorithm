#include <cstdio>

int tree[400005]; // 입력값의 4*N으로 할당한다고 함.

int init(int node, int s, int e){
    if(s == e) return tree[node] = 1;
    int mid = (s + e) >> 1;

    return tree[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}

int query(int node, int s, int e, int k){
    tree[node]--;
    if(s == e) return s; // 리프 노드에 도달하면 해당 인덱스를 반환
    int mid = (s + e) >> 1; //  중간값을 구함

    // 왼쪽 자식 노드의 값이 k보다 크거나 같으면 왼쪽 자식 노드로 이동
    if(tree[2 * node] >= k) 
        return query(2 * node, s, mid, k);
    else
        return query(2 * node + 1, mid + 1, e, k - tree[2 * node]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    init(1, 1, n); // 세그먼트 트리를 초기화

    int x = k; // x를 k로 초기화
    printf("<");
    for(int i = 0; i < n - 1; i++){
        printf("%d, ", query(1, 1, n, x)); // x 값을 인덱스로 가지는 원소를 출력
        x += k - 1; // x 값을 k-1만큼 증가시킴

        if(x % tree[1] == 0) x = tree[1];
        else x %= tree[1];
    }
    printf("%d>\n", query(1, 1, n, x)); // 마지막 원소를 출력
    printf(">"); // 마지막에 출력되는 ,를 없애기 위해 추가
}