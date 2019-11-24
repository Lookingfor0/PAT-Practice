#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
double P, r, lp = 10000000000.0;  // 其实这里不用管价格，只用计算DFS的深度就行了，到最后在计算lowest price
vector<int> a[100000];

void DFS(int i, double sum) {
    if(a[i].size() == 0) {
        if(sum < lp) {
            lp = sum;
            cnt = 1;
        } else if((int)(sum * 10000) == (int)(lp * 10000))
            cnt++;
    } else {
        for(int j = 0; j < a[i].size(); j++)
            DFS(a[i][j], sum * (1 +r / 100));
    }
}

int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    for(int i = 0; i < N; i++) {
        int k, d;
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &d);
            a[i].push_back(d);
        }
    }
    DFS(0, P);
    printf("%.4f %d", lp, cnt);
    return 0;
}

