#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, K, u, v, l[1000];
    unordered_map<int, vector<int>> G;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < M; i++) {
        unordered_map<int, int> in;
        scanf("%d", &K);
        for(int j = 0; j < K; j++) {
            scanf("%d", &l[j]);
            in[l[j]]++;
        }
        bool flag = true;
        for(int j = 0; j < K && flag; j++) {
            auto v = G[l[j]];
            for(int k = 0; k < v.size(); k++) {
                if(in[v[k]] != 0) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

