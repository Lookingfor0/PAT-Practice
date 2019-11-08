#include <cstdio>

using namespace std;

int main() {
    int num[10001], K, fi, mfi, mli, sum, msum;
    scanf("%d", &K);
    if(K <= 0) return 0;
    for(int i = 0; i < K; i++)
        scanf("%d", &num[i]);
    sum = 0;
    msum = -1;  // 这里初始化为 -1 是防止 0 和复数同时出现输出结果和全负一样(如：0 -1 0)
    mfi = fi = 0;
    mli = K - 1;
    for(int i = 0; i < K; i++) {
        sum += num[i];
        if(sum > msum) {
            msum = sum;
            mli = i;
            mfi = fi;
        }
        if(sum < 0) {  // sum = 0 不用改变fi，因为要取最小的下标
            fi = i + 1;
            sum = 0;
        }
    }
    if(msum < 0) msum = 0;
    printf("%d %d %d\n", msum, num[mfi], num[mli]);
    return 0;
}

