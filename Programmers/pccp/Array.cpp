#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*
입차 후 출차 후 입차
1. 기본요금 + 추가요금으로 산정
2. 같은 날에 입차하고 출차 내역이 없으면 23:59에서 뺀 시각만큼 진행

입차 -> 출차 내역이 있어야 그 후에 입차하면 뺄 수 있다.
map<'', class>  -> 차량의 번호로 <시각과 내역> 을 구분할 수 있다.

입차 - 출차 -> 최종 시간만 있으면 가격은 구할 수 있다.
*/
class Car {
public:
    int time;
    string content;
    int result;
};

int getCeil(int x, int basic_time, int extra_time) {
    if (x < basic_time) return 0;
    else {
        return ceil(((float)x - basic_time) / extra_time); // 이 부분 float와 반올림을 잘 생각해야 함.
    }
}

int getPrice(int basic_time, int basic_fee, int extra_time, int extra_fee, int x) {
    return basic_fee + getCeil(x, basic_time, extra_time) * extra_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, Car> car_map;
    int basic_time = fees[0];
    int basic_fee = fees[1];
    int extra_time = fees[2];
    int extra_fee = fees[3];

    for (const auto& x : records) {
        stringstream ss(x);
        string h, m, np, con;
        getline(ss, h, ':');
        getline(ss, m, ' ');
        getline(ss, np, ' ');
        getline(ss, con, ' ');

        // 시간 계산
        int cal = stoi(h) * 60 + stoi(m);

        // 내용에 따라서 가격정책을 진행
        auto it = car_map.find(np);
        if (it != car_map.end()) {
            if (con == "OUT") { // 출차일 때
                car_map[np].result += (cal - car_map[np].time);
                car_map[np].content = con;
                car_map[np].time = cal;
            }
            else { // 이후 입차일 때
                car_map[np].content = con;
                car_map[np].time = cal;
            }
        }
        else { // 최초에는 입차만 있을 것으로 가정
            Car car;
            car.time = cal;
            car.content = con;
            car.result = 0;
            car_map[np] = car;
        }
    }

    // 마지막으로 입차가 남은 차량에 대해서 23:59까지의 요금을 책정
    int final_time = 23 * 60 + 59;
    for (auto entry : car_map) {
        auto k = entry.first;
        auto v = entry.second;
        if (v.content == "IN") { // 입차라면 마지막까지 더해야 한다.
            answer.push_back(getPrice(basic_time, basic_fee, extra_time, extra_fee, v.result + (final_time - v.time)));
        }
        else {
            answer.push_back(getPrice(basic_time, basic_fee, extra_time, extra_fee, v.result));
        }
    }

    return answer;
}
int main() {
	vector<string> vec2{ "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<int> vec1{180, 5000, 10, 600};

    solution(vec1, vec2);
}