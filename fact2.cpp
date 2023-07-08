#include <iostream>
#include <vector>
using namespace std;

int fact(int n);
int main(){
    int n;
    cin >> n;

    int ans = fact(n);
    cout << ans;
}

int fact(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return fact(n-1) + fact(n-2);
}