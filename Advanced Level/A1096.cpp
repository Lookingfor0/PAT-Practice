#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long N, t;
    scanf("%ld", &N);
    int len = 0, first, maxn = sqrt(N) + 1;
    for(int i = 2; i <= maxn; i++) {
        t = 1;
        int j;
        for(j = i; j <= maxn; j++) {
            t *= j;
            if(N % t != 0) break;
        }
        if(j - i > len) {
            len = j - i;
            first = i;
        }
    }
    if(len == 0) {  // 质数
        first = N;
        len = 1;
    }
    printf("%d\n%d", len, first);
    for(int i = first + 1; i < first + len; i++)
        printf("*%d", i);
    return 0;
}

