#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> fact;
    fact.push_back(1);
    fact.push_back(1);
    for(int i = 2; i < n; i++){
        fact.push_back(fact[i-1] + fact[i-2]);
    }    
    cout << fact[n-1];
}