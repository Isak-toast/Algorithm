
#include <bits/stdc++.h>
using namespace std;

/*
N번째 항까지 가면서 max값을 구하라.

배열이 늘어남 -> vector를 사용하는데

첫 숫자를 주고 끊어질 때까지 계속
*/
int ans = 1;
int main(){
    int N;
    cin >> N;

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vector<int> res;

    if(N == 1 || N == 2) {
        ans = 1;
    }
    else { // 3항 이상
        for(int n = 3; n <= N; n++){
            // two pointer로 진행
            for(int i = 0, j = 1; i < vec.size(); i = j){
                int cnt = 1;

                for(j = i+1; j < vec.size(); j++){
                    if(vec[i] == vec[j]){
                        cnt++; 
                    }
                    else{
                        res.push_back(vec[i]);
                        res.push_back(cnt);
                        cnt = 1;
                        i = j;
                    }
                    ans = max(ans, vec[j]);
                }
                // if(j >= vec.size()){
                //     res.push_back(vec[i]);
                //     res.push_back(cnt);
                //     break;
                // }
            }

            // res vector는 복사 후 비움
            for(auto i = res.begin(); i != res.end(); i++) cout << *i;
            vec.assign(res.begin(), res.end());
            res.clear();

        }      
    }
    cout << ans;
}