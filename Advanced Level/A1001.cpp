#include <iostream>
#include <stack>

using namespace std;


int main() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	if (c < 0) {
		cout << '-';
		c = -c;
	} else if (c == 0) {
		cout << '0';
		return 0;
	}
	stack<int> s;
	while (c > 0) {
		s.push(c % 10);
		c /= 10;
	}
	int count = s.size();
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		count--;
		if (count % 3 == 0 && s.size()) {
			cout << ',';
			count = 0;
		}
	}
	return 0;
}