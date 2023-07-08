#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int P;
    cin >> P;
    int output[4] = {0,};
    for(int i = 0; i < 5; i++){
        int year, cls, num;
        cin >> year >> cls >> num;

        if(year == 1) output[3] += 1;
        else if(cls == 1 || cls == 2) output[0] += 1;
        else if(cls == 3) output[1] += 1;
        else if(cls == 4) output[2] += 1;
    }
    // for(int i = 0; i < 4; i++) cout << output[i] << endl;
    cout << output[0] << endl;
    cout << output[1] << endl;
    cout << output[2] << endl;
    cout << output[3];
}