#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> vec1{ 1,2,3,4,5 };
vector<int> vec2{ 1,2,30,40,50 };

void Print_Vec(const vector<int> &vec) {
    for (const int &it : vec) {
        cout << it << " ";
    }
    cout << "\n";
}

void Union_Func(){
    cout << "Union_Func\n";
    vector<int> buff(vec1.size() + vec2.size());
    auto iter = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
    buff.erase(iter, buff.end());

    Print_Vec(buff);
}

void Intersection_Func() {
    cout << "Intersection_Func\n";
    vector<int> buff(vec1.size() + vec2.size());
    auto iter = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin()); // last의 iterator 위치를 반환하는 듯
    buff.erase(iter, buff.end());

    Print_Vec(buff);
}

void Difference_Func() {
    cout << "Defference_Func\n";

    vector<int> buff(vec1.size() + vec2.size());
    auto iter = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
    buff.erase(iter, buff.end());

    Print_Vec(buff);
}


int main()
{
    Print_Vec(vec1);
    Print_Vec(vec2);
    vec1.insert( vec1.end(), vec2.begin(), vec2.end() );
    Print_Vec(vec1);

    cout << "\n===========\n\n";

    Union_Func();
    Intersection_Func();
    Difference_Func();

    return 0;
}
