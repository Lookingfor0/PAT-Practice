#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)  // 这里写 i < sqrt(n) + 1 就过不了测试点1
        if(n % i == 0) return false;
    return true;
}

int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    while(!isPrime(M)) M++;
    vector<int> a(N), t(M);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    for(int i = 0; i < N; i++) {
        int k, p;
        for(k = 0; k <= M / 2; k++) {
            p = (a[i] + k * k) % M;
            if(t[p] == 0) {
                t[p] = a[i];
                break;
            }
        }
        if(i != 0) printf(" ");
        if(k > M / 2) printf("-");
        else printf("%d", p);
    }
    printf("\n");
    return 0;
}

