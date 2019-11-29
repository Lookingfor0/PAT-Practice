#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long p, a[100000];
    int N, ans = 0, del;
    scanf("%d%lld", &N, &p);
    for(int i = 0; i < N; i++) scanf("%lld", &a[i]);
    sort(a, a + N);
    for(int i = 0; i < N; i++) {
        del = ans;
        if(i + del >= N) break;
        while(i + del < N && a[i + del] <= p * a[i]) del++;
        if(del > ans) ans = del;
    }
    printf("%d", ans);
    return 0;
}

