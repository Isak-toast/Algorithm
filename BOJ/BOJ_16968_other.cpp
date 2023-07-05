#include <cstdio>
#include <iostream>

int c = 1;
char s[6];
int main() {
    // scanf("[^\n]%s", s + 1); // char 배열 입력 (공백도 함께 입력)
    scanf("%s", s + 1); // char 배열 입력
    printf("%s", s);    // char 배열 출력 -> 앞에는 공백이라서 줄이 이어서 출력이 되지 않음
    printf("%s", s+1);  // char 배열 출력

    // std::string s, s2;
    // std::cin >> s; // 공백을 기준으로 입력 받는다
    // std::getline(std::cin, s2, '\n'); // '\n'을 기준으로 입력을 받음
    // std::cout << s << std::endl;
    // std::cout << s2 << std::endl;

	for (int i = 1; s[i]; i++)
		c *= (s[i] == 'c' ? 26 : 10) - (s[i] == s[i - 1]);

	// printf("%d", c);
}