#include <iostream>
#include <string>

using namespace std;

int main() {
    char d;
    int N;
    string s;
    scanf("%c%d", &d, &N);
    s += d;
    for(int i = 1; i < N; i++) {
        string t;
        int j = 0;
        while(j < s.size()) {
            d = s[j];
            int cnt = 0;
            while(j < s.size() && s[j] == d) {
                cnt++;
                j++;
            }
            t += d;
            t += (cnt + '0');
        }
        s = t;
    }
    printf("%s\n", s.c_str());
    return 0;
}

