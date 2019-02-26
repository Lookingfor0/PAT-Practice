#include <iostream>
#include <cmath>
#include <map>

using namespace std;


int main() {
	int K, N;
	double a;
	map<int, double> mp;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
		mp[N] = a;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
		if (mp.find(N) != mp.end()) {
			mp[N] += a;
			if (abs(mp[N]) < 1e-6) mp.erase(N);
		} else
			mp[N] = a;
	}
	cout << mp.size();
	if (mp.size() != 0) cout << ' ';
	auto i = mp.end();
	cout.precision(1);
	cout.setf(ios::fixed);
	while (i != mp.begin()) {
		i--;
		cout << i->first << ' ' << i->second;
		if (i != mp.begin()) cout << ' ';
	}
	return 0;
}