#include <iostream>
#include <list>
#include <iterator>
#include <sstream>

void josephus(int n, int k) {
    std::list<int> circle;  // 원형 연결 리스트 생성
    for (int i = 1; i <= n; i++) {
        circle.push_back(i);  // 리스트에 1부터 n까지의 숫자를 추가
    }

    std::stringstream ss;  // 결과를 저장할 문자열 스트림
    ss << "<";
    
    auto it = circle.begin();  // 리스트의 시작을 가리키는 반복자
    while (!circle.empty()) {  // 리스트가 비어있지 않은 동안
        for (int i = 1; i < k; i++) {  // k-1번 반복
            it++;  // 반복자를 다음 원소로 이동
            if (it == circle.end()) {  // 반복자가 리스트의 끝에 도달하면
                it = circle.begin();  // 반복자를 리스트의 시작으로 이동
            }
        }

        ss << *it;  // 요세푸스 순열에 현재 원소 추가
        it = circle.erase(it);  // 현재 원소를 리스트에서 삭제하고 반복자를 다음 원소로 이동
        if (!circle.empty()) {
            ss << ", ";
        }

        if (it == circle.end()) {  // 반복자가 리스트의 끝에 도달하면
            it = circle.begin();  // 반복자를 리스트의 시작으로 이동
        }
    }
    ss << ">";

    std::cout << ss.str() << std::endl;  // 결과 출력
}

int main() {
    int n, k;
    std::cin >> n >> k;  // n과 k를 입력받음
    josephus(n, k);  // 요세푸스 순열을 계산하고 출력
    return 0;
}
