// 直接用数组暴力遍历
#include <cstdio>

int main() {
    int k1, k2, te, cnt = 0;
    double coe[1001] = {0.0}, tc, ans[2001] = {0.0};
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++) {
        scanf("%d%lf", &te, &tc);
        coe[te] = tc;
    }
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++) {
        scanf("%d%lf", &te, &tc);
        for(int j = 0, c = 0; c < k1; j++) {
            if(coe[j] != 0.0) {
                c++;
                ans[te + j] += tc * coe[j];
            }
        }
    }
    for(int i = 0; i < 2001; i++) {
        if(ans[i] != 0.0) cnt++;
    }
    printf("%d", cnt);
    for(int i = 2000; i >= 0; i--) {
        if(ans[i] != 0.0) printf(" %d %.1f", i, ans[i]);
    }
    return 0;
}

