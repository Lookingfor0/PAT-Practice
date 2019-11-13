#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    vector<int> ans, G[1001], ind(1001);
    scanf("%d%d", &N ,&M);
    while(M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        auto tempd = ind;
        int v;
        bool flag = true;
        for(int j = 0; j < N; j++) {
            scanf("%d", &v);
            if(flag && tempd[v] != 0) {
                ans.push_back(i);
                flag = false;
            }
            if(flag) {
                for(int k = 0; k < G[v].size(); k++)
                    tempd[G[v][k]]--;
            }
        }
    }
    for(int i = 0; i < ans.size() - 1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size() - 1]);
    return 0;
}

