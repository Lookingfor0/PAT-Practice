#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    string ld[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string hd[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    while(N--) {
        string a, b;
        getline(cin, a);
        if(isdigit(a[0])) {
            int num = stoi(a);
            int d1 = num / 13, d2 = num % 13;
            if(d1 > 0) printf("%s", hd[d1].c_str());
            if(d1 > 0 && d2 > 0) printf(" ");
            if(d2 > 0 || num == 0) printf("%s", ld[d2].c_str());
        } else {
            int t1 = 0, t2 = 0;
            if(a.length() > 4) {
                b = a.substr(4, 3);
                a = a.substr(0, 3);
            }
            for(int i = 1; i < 13; i++) {
                if(a == ld[i] || b == ld[i]) t2 = i;
                if(a == hd[i]) t1 = i;
            }
            printf("%d", t1 * 13 + t2);
        }
        printf("\n");
    }
    return 0;
}

