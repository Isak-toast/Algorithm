#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int ans = 0;
    ll n, k;
    cin >> n >> k;

    vector<ll> vect;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vect.push_back(v);
    }
    sort(vect.begin(), vect.end());

    // n명이 2마리를 고를 수 있는 최대 수
    int i = 0, j = n - 1;
    while (i < j) {
        if (vect[i] + vect[j] <= k) {
            ans++;
            i++;
            j--;
        }
        else {
            j--;
        }
    }

    cout << ans << endl;
    return 0;
}