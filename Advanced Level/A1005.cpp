#include <iostream>
#include <string>

using namespace std;


int main() {
	string n, e[10] = { "zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine" };
	cin >> n;
	int sum = 0;
	for (auto i = n.begin(); i != n.end(); i++) {
		sum += *i - '0';
	}
	n = to_string(sum);
	for (auto i = n.begin(); i != n.end(); i++) {
		cout << e[*i - '0'];
		if (i + 1 != n.end()) cout << ' ';
	}
	return 0;
}