/*
Binary Search -> O(log N)

https://www.piratekingdom.com/leetcode/templates/binary-search
*/
#include <vector>
using namespace std;

int binarySearch(vector<int> &list, int target){
    int l = 0, r = list.size()-1;

    while(l < r){
        int mid = (l + r) / 2;
        //if(list[mid] < target){ // list가 자연수 집합인 경우에 가능 mid
        if(mid < target){ // list가 자연수 집합인 경우에 가능 mid
            l = m + 1; 
        }
        else {
            r = m;
        }
    }

    return l;
}

int main(){
    return 0;
}