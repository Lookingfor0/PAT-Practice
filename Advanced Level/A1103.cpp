#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, P, maxsum = 0;
vector<int> temp, ans, v;

int Sum() {
    int s = 0;
    for(int i = 0; i < temp.size(); i++)
        s += temp[i];
    return s;
}

void DFS(int n, int k, int index) {
    for(int i = index; i > 0; i--) {
        temp.push_back(i);
        if(k == 1) {
            int ts = Sum();
            if(n == v[i] && ts > maxsum) {
                maxsum = ts;
                ans = temp;
            }
        } else if(n > v[i]) {
            DFS(n - v[i], k - 1, i);
        }
        temp.pop_back();
    }
}

int main() {
    scanf("%d%d%d", &N, &K, &P);
    int p = 0, t = 1;
    while(p <= N) {
        v.push_back(p);
        p = pow(t++, P);
    }
    DFS(N, K, v.size() - 1);
    if(ans.size() < K) printf("Impossible");
    else {
        printf("%d = %d^%d", N, ans[0], P);
        for(int i = 1; i < K; i++)
            printf(" + %d^%d", ans[i], P);
    }
    return 0;
}

