#include <iostream>
#include <string>
#include <vector>

using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string c[6] = { "Ge","Shi", "Bai", "Qian", "Wan", "Yi" };

int main() {
    string s;
    vector<string> ans;
    cin >> s;
    bool zero = false;
    if(stoi(s) == 0) {
        cout << num[0];
        return 0;
    }
    int i = 0;
    if(s[0] == '-') {
        ans.push_back("Fu");
        i++;
    }
    for(;i < s.size(); i++) {
        int t = s.size() - i - 1;
        if(s[i] == '0') {
            zero = true;
        } else {
            if(zero) ans.push_back(num[0]);
            zero = false;
            ans.push_back(num[s[i] - '0']);
        }
        if(t == 8)
            ans.push_back(c[5]);
        else if(t == 4)
            ans.push_back(c[4]);
        else if(t != 0 && !zero)
            ans.push_back(c[t % 4]);
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" ");
        printf("%s", ans[i].c_str());
    }
    return 0;
}

