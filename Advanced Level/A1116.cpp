#include <iostream>

using namespace std;

bool isPrime(int N) {
    if(N < 2) return false;
    for(int i = 2; i * i <= N; i++) {
        if(N % i == 0) return false;
    }
    return true;
}

int main() {
    int N, K, r[10001] = {0}, id;
    bool checked[10001] = {0};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &id);
        if(i == 1)
            r[id] = 1;
        else if(isPrime(i))
            r[id] = 2;
        else
            r[id] = 3;
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if(checked[id])
            printf("Checked\n");
        else if(r[id] == 0)
            printf("Are you kidding?\n");
        else {
            if(r[id] == 1)
                printf("Mystery Award\n");
            else if(r[id] == 2)
                printf("Minion\n");
            else
                printf("Chocolate\n");
            checked[id] = true;
        }
    }
    return 0;
}

