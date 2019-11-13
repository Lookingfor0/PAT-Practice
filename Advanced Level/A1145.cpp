#include <iostream>

using namespace std;

bool isPrime(int N) {
    if(N <= 1) return false;
    for(int i = 2; i * i <= N; i++) {
        if(N % i == 0) return false;
    }
    return true;
}

int main() {
    int MSize, N, M, t[100000] = {0}, st = 0, x;
    scanf("%d%d%d", &MSize, &N, &M);
    while(!isPrime(MSize))
        MSize++;
    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        int index = x % MSize, j;
        for(j = 1; j < MSize && t[index] != 0; j++)
            index = (x + j * j) % MSize;
        if(j >= MSize) printf("%d cannot be inserted.\n", x);
        else t[index] = x;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d", &x);
        for(int j = 0; j <= MSize; j++) {
            int index = (x + j * j) % MSize;
            st++;
            if(t[index] == 0 || t[index] == x)
                break;
        }
    }
    printf("%.1f\n", double(st) / M);
    return 0;
}

