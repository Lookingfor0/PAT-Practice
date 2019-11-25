#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long lmax = 0, rmin = 1000000000, a[100000];
    bool flag[100000];
    vector<long long> ans;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        if(lmax < a[i]) {
            flag[i] = true;
            lmax = a[i];
        }
    }
    for(int i = N - 1; i >= 0; i--) {
        if(a[i] < rmin) {
            if(flag[i]) ans.push_back(a[i]);
            rmin = a[i];
        }
    }
    printf("%d\n", ans.size());
    for(int i = (int)ans.size() - 1; i >= 0 ; i--) {
        printf("%lld", ans[i]);
        if(i != 0) printf(" ");
    }
    printf("\n");  // 不加这个过不了测试点2。。。
    return 0;
}

