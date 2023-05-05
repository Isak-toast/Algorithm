#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

/*
 * N명의 사람이 원을 이루면 앉음
 * K번째 사람을 제거 -> N명이 모두 제거될 때까지 계속
 * 
 * (N,K) 요세푸스 순열이라고 함
 * sol) 입력 자료구조를 순회하면서 값을 빼서 순열을 만든다.
 * 큐 자료구조를 활용
 * 앞에 있는 원소를 뒤로 위치 -> 연산 1번
 * K번 마다 순열 리스트에 저장
 */

void version1() {
    int N, K;
    std::cin >> N >> K;
    
    std::queue<int> input;
    for (int i = 1; i <= N; i++) {
        input.push(i);
    }
    
    std::vector<int> josephus;
    int cur = 1;
    while (!input.empty()) {
        if (cur == K) {
            cur = 1;
            josephus.push_back(input.front());
            input.pop();
        } else {
            cur++;
            input.push(input.front());
            input.pop();
        }
    }
    
    std::stringstream ss;
    ss << "<" << josephus[0];
    for (int i = 1; i < N; i++) {
        ss << ", " << josephus[i];
    }
    ss << ">";
    std::cout << ss.str() << std::endl;
}

int main() {
    version1();
    return 0;
}
