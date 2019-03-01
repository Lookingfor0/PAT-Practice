#include <iostream>
#include <string>

using namespace std;


int main() {
	int M;
	string id_in, id_out, t_in, t_out;
	string id_temp, temp_in, temp_out;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> id_temp >> temp_in >> temp_out;
		if (!t_in.length() || temp_in < t_in) {
			id_in = id_temp;
			t_in = temp_in;
		}
		if (!t_out.length() || temp_out > t_out) {
			id_out = id_temp;
			t_out = temp_out;
		}
	}
	cout << id_in + ' ' + id_out << endl;
	return 0;
}