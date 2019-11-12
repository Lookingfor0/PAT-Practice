#include <iostream>
#include <unordered_set>

using namespace std;

struct edge {
    int u, v;
}e[10000];

int main() {
    int N, M, K, u, v, color[10000];
    unordered_set<int> s;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        e[i] = {u, v};
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        s.clear();
        for(int j = 0; j < N; j++) {
            scanf("%d", &color[j]);
            s.insert(color[j]);
        }
        bool flag = true;
        for(int j = 0; j < M; j++) {
            u = e[j].u;
            v = e[j].v;
            if(color[u] == color[v]) {
                flag = false;
                printf("No\n");
                break;
            }
        }
        if(flag) printf("%d-coloring\n", s.size());
    }
    return 0;
}

