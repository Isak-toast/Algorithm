#include <bits/stdc++.h>

int main(){
    int f[60] = {1,0}, T, a;
    for(a=0;a<50;a++)
        f[a+2] = f[a+1] + f[a];

    scanf("%d", &T);
    while(T--){
        scanf("%d", &a);
        printf("%d %d\n", f[a], f[a+1]);
    }
    return 0;
}