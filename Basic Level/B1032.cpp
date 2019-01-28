#include <cstdio>

const int nMax = 100000;

int main() {
    int n, sMax = -1, idMax = 1, id, score;  // 这里要注意编号时从 1 开始
    int s[nMax] = {0};
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &id, &score);
        s[id - 1] += score;
        if(s[id - 1] > sMax) {
            sMax = s[id - 1];
            idMax = id;
        }
    }
    printf("%d %d\n", idMax, sMax);
    return 0;
}

