#include <stdio.h>

using namespace std;

int main() {
    int h1, h2, N;
    int a, next[100000] = {0};
    char nodes[100000];
    scanf("%d %d %d", &h1, &h2, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a);
        getchar();
        nodes[a] = getchar();  //貌似没用到节点储存的字符, 但是不存好像通不过
        scanf("%d", &next[a]);
    }
    int l1 = 0, l2 = 0, t;
    t = h1;
    while(t != -1) {
        l1++;
        t = next[t];
    }
    t = h2;
    while(t != -1) {
        l2++;
        t = next[t];
    }
    if(l1 > l2) {
        for(int i = 0; i < l1 - l2; i++)
            h1 = next[h1];
    } else {
        for(int i = 0; i < l2 - l1; i++)
            h2 = next[h2];
    }
    while(h1 != h2) {
        h1 = next[h1];
        h2 = next[h2];
    }
    if(h1 == -1)
        printf("-1\n");
    else
        printf("%05d\n", h1);
    return 0;
}

