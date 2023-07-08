#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;

    string ans;
    if(str == "fdsajkl" || str == "jkl;fdsa")
        ans = "in-out";
    else if(str == "asdf;lkj" || str == ";lkjasdf")
        ans = "out-in";
    else if(str == "asdfjkl;")
        ans = "stair";
    else if(str == ";lkjfdsa")
        ans = "reverse";
    else
        ans = "molu";
    cout << ans;
}