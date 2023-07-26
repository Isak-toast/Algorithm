#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*
���� �� ���� �� ����
1. �⺻��� + �߰�������� ����
2. ���� ���� �����ϰ� ���� ������ ������ 23:59���� �� �ð���ŭ ����

���� -> ���� ������ �־�� �� �Ŀ� �����ϸ� �� �� �ִ�.
map<'', class>  -> ������ ��ȣ�� <�ð��� ����> �� ������ �� �ִ�.

���� - ���� -> ���� �ð��� ������ ������ ���� �� �ִ�.
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
        return ceil(((float)x - basic_time) / extra_time);
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

        // �ð� ���
        int cal = stoi(h) * 60 + stoi(m);

        // ���뿡 ���� ������å�� ����
        auto it = car_map.find(np);
        if (it != car_map.end()) {
            if (con == "OUT") { // ������ ��
                car_map[np].result += (cal - car_map[np].time);
                car_map[np].content = con;
                car_map[np].time = cal;
            }
            else { // ���� ������ ��
                car_map[np].content = con;
                car_map[np].time = cal;
            }
        }
        else { // ���ʿ��� ������ ���� ������ ����
            Car car;
            car.time = cal;
            car.content = con;
            car.result = 0;
            car_map[np] = car;
        }
    }

    // ���������� ������ ���� ������ ���ؼ� 23:59������ ����� å��
    int final_time = 23 * 60 + 59;
    for (auto entry : car_map) {
        auto k = entry.first;
        auto v = entry.second;
        if (v.content == "IN") { // ������� ���������� ���ؾ� �Ѵ�.
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