#include <iostream>

using namespace std;

int main() {
    int N, t;
    bool a[100001] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &t);
        if(t <= 0 || t > 100000) continue;
        a[t] = true;
    }
    int ans;
    for(ans = 1; ans <= 100000; ans++)
        if(!a[ans]) break;
    printf("%d\n", ans);
    return 0;
}

