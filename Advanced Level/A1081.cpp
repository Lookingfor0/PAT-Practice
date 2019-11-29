#include <iostream>
#include <algorithm>

using namespace std;

struct Num {
    long int nu, de, in;
}ans, t;

int gcd(long int a, long int b) {  // a and b are positive numbers
    return a % b == 0 ? b : gcd(b, a % b);
}

void Simplify(struct Num &A) {
    long int g = gcd(abs(A.nu), abs(A.de));
    A.nu /= g;
    A.de /= g;
}

int main() {
    int N;
    scanf("%d", &N);
    if(N == 0) return 0;
    scanf("%ld/%ld", &ans.nu, &ans.de);
    Simplify(ans);
    while(--N) {
        scanf("%ld/%ld", &t.nu, &t.de);
        ans.nu = ans.nu * t.de + ans.de * t.nu;
        ans.de *= t.de;
        Simplify(ans);
    }
    ans.in = ans.nu / ans.de;
    ans.nu = ans.nu - ans.in * ans.de;
    if(ans.in) {
        printf("%ld", ans.in);
        if(ans.nu) printf(" ");
    }
    if(ans.nu) printf("%ld/%ld", ans.nu, ans.de);
    if(!ans.in && !ans.nu) printf("0");
    return 0;
}

