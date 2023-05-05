#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

/*
은진이는 요즘 마피아라는 게임에 빠져 있다. 이 게임의 규칙은 다음과 같다.

참가자는 두 그룹으로 나누어진다. 한 그룹은 마피아이고, 또 다른 그룹은 선량한 시민이다. 마피아의 정체는 시민에게 알려져 있지 않다. 참가자의 번호는 0번부터 시작한다.
참가자가 짝수 명 남았을 때는 밤이다. 밤에는 마피아가 죽일 사람 한 명을 고른다. 죽은 사람은 게임에 더 이상 참여할 수 없다.
참가자가 홀수 명 남았을 때는 낮이다. 낮에는 참가자들이 가장 죄가 있을 것 같은 사람 한 명을 죽인다.
만약 게임에 마피아가 한 명도 안 남았다면, 그 게임은 시민 팀이 이긴 것이고, 시민이 한 명도 안 남았다면, 그 게임은 마피아 팀이 이긴 것이다. 게임은 즉시 종료된다.
게임을 잠시 동안 한 후에 은진이는 지금 이 게임에서 자기가 마지막으로 남은 마피아라는 것을 알았다. 따라서 은진이는 이 게임을 이기기 위해 방법을 생각하기 시작했다.

각 사람의 유죄 지수가 주어진다. 이 유죄 지수는 낮에 시민들이 어떤 참가자를 죽일 것인지 고를 때 쓰인다. 그리고 참가자 간의 반응을 나타내는 2차원 배열 R이 주어진다.

게임은 다음과 같이 진행된다.

밤에는 마피아가 죽일 사람을 한 명 고른다. 이 경우 각 사람의 유죄 지수가 바뀐다. 만약 참가자 i가 죽었다면, 다른 참가자 j의 유죄 지수는 R[i][j]만큼 변한다.
낮에는 현재 게임에 남아있는 사람 중에 유죄 지수가 가장 높은 사람을 죽인다. 그런 사람이 여러 명일 경우 그중 번호가 가장 작은 사람이 죽는다. 이 경우 유죄 지수는 바뀌지 않는다.
은진이는 되도록이면 이 게임을 오래 하고 싶다. 은진이가 이 게임에 정말 천재적으로 임하여 매번 최적의 선택을 할 때, 몇 번의 밤이 지나는지 출력하는 프로그램을 작성하시오.
*/
int N;
std::vector<std::vector<int>> R;
std::vector<int> guilty;
std::vector<bool> killed;
int ans = 0;
int eunjin;
int night = 0;

void addGuilty(int i) { // i번째 사람을 죽였을 때 guilty를 더해줌
    for (int j = 0; j < N; j++) {
        if (killed[j]) continue; // 죽은 사람은 더해주지 않음
        guilty[j] += R[i][j]; // 죽은 사람이 아니면 guilty를 더해줌
    }
}

void subGuilty(int i) { // i번째 사람을 살렸을 때 guilty를 빼줌
    for (int j = 0; j < N; j++) {
        if (killed[j]) continue; // 죽은 사람은 빼주지 않음
        guilty[j] -= R[i][j];
    }
}

int justice() { // 가장 유죄 지수가 높은 사람을 찾음
    int max = 0;
    int j = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (killed[i]) continue; // 죽은 사람은 빼줌
        if (max <= guilty[i]) { // 유죄 지수가 높은 사람을 찾음
            max = guilty[i];
            j = i;
        }
    }
    return j;
}

// 모든 최적해를 찾는다.
bool flag = false;
void game(int cnt, int total, int mafia, int cityzen) {
    if (flag) return;
    if ((total & 1) == 0) { // 밤
        if (cityzen == 1) { // 마피아가 이긴 경우
            night = std::max(night, cnt + 1);
            flag = true;
            return;
        }
		// 마피아가 죽일 사람을 고른다.
		// 모든 경우의 수를 다 따져본다. 그러므로 killed[i] = true로 설정하고 false로 복원한다.
        for (int i = 0; i < N; i++) {
            if (i == eunjin || killed[i]) continue;
            killed[i] = true;
            addGuilty(i);
            game(cnt + 1, total - 1, mafia, cityzen - 1); // 재귀 호출
            subGuilty(i);
            killed[i] = false;
        }
    } else {
		// 낮에는 모든 인원 중 가장 유죄 지수가 높은 사람을 죽인다.
        int j = justice();
        if (j == eunjin) {
            night = std::max(night, cnt);
            return;
        }
        killed[j] = true;
        game(cnt, total - 1, mafia, cityzen - 1);
        killed[j] = false;
    }
}

int main() {
	// 입력 속도 향상, 출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    guilty.resize(N); 	// guilty 벡터의 크기를 N으로 설정
    for (int i = 0; i < N; i++) {
        std::cin >> guilty[i];	// 유죄 지수 입력, Interger.parseInt(stk.nextToken())와 같은 기능
    }
    R.resize(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> R[i][j];
        }
    }
    std::cin >> eunjin;
    killed.resize(N, false); // boolean 배열의 크기를 N, 모든 요소를 false로 설정

    int total = N;
    int mafia = 1;
    int cityzen = N - 1;

    if (total != mafia) { // 마피아가 한 명도 없을 때
        game(0, total, mafia, cityzen); // 밤의 횟수, 총 인원, 마피아 인원, 시민 인원
    }
    std::cout << night << '\n';

    return 0;
}
