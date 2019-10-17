#include <cstdio>

using namespace std;

const int maxn = 100000;
int prime[maxn];

// 先求出素数表
void Find_Prime() {
    int p = 0;
    bool flag[maxn] = {0};
    // 筛法
    for(int i = 2; i < maxn; i++) {
        if(!flag[i]) {
            prime[p++] = i;
            for(int j = i + i; j < maxn; j += i)
                flag[j] = true;
        }
    }
}

int main() {
    long int num, n;
    int fac[10] = {0}, exp[10] = {0}, p = 0;  // fac 为质因子，p 为质因子操作下标
    scanf("%ld", &num);
    if(num == 1) {  // 1 单独处理
        printf("1=1\n");
        return 0;
    }
    Find_Prime();
    n = num;  // 之后要对 n 进行操作
    for(int i = 0; i < maxn && n != 1; i++) {
        if(n % prime[i] == 0) {
            fac[p] = prime[i];
            while(n % prime[i] == 0) {
                exp[p]++;
                n /= prime[i];
            }
            p++;
        }
    }
    if(n == 1) {
        printf("%ld=%d", num, fac[0]);
        if(exp[0] != 1) printf("^%d", exp[0]);
        for(int i = 1; i < p; i++) {
            printf("*%d", fac[i]);
            if(exp[i] != 1) printf("^%d", exp[i]);
        }
    } else {
        // 此时只有自己本身一个质因子
        printf("%ld=%ld\n", num, num);
    }
    return 0;
}

