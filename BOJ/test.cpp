#include <iostream>
#include <set>
using namespace std;

int c = 1;
set<int> s;
int main(){
    s.insert(1);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(11);
    s.insert(15);

    cout << s.size();
}