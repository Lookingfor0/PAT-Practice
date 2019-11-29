#include <iostream>
#include <string>

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    string s, ans;
    int exp, p;
    cin >> s;
    p = s.find('E');
    exp = stoi(s.substr(p + 1));
    if(s[0] == '-') cout << '-';
    if(exp < 0) {
        cout << "0.";
        for(int i = -1 - exp; i > 0; i--) cout << '0';
        cout << s[1] << s.substr(3, p - 3);
    } else if(exp == 0) {
        cout << s.substr(1, p - 1);
    } else {
        int t = p - 3;
        cout << s[1];
        if(exp < t) {
            cout << s.substr(3, exp) << '.' << s.substr(3 + exp, t - exp);
        } else {
            cout << s.substr(3, p - 3);
            for(int i = 0; i < exp - p + 3; i++) cout << '0';
        }
    }
    return 0;
}

