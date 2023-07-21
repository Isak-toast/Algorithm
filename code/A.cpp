#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int n;
    cin >> n;
    int i = 1;
    long long ans = i;
    while (n > 0) {
        ans *= i;
        i++;
        n--;
    }
    cout << ans / 604800 << endl;
}