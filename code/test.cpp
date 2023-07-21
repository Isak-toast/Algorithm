#include <string>
#include <iostream>
using namespace std;

int main() {
	string str(10, '.');
	cout << str << endl;

	str[5] = '*';
	cout << str << endl;
}