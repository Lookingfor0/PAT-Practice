#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3fffffff;

int main() {
    int N, M, K, G[201][201];
    int u, v, d;
    scanf("%d%d", &N, &M);
    fill(G[0], G[0] + 201 * 201, INF);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &u, &v, &d);
        G[u][v] = G[v][u] = d;
    }
    scanf("%d", &K);
    bool vis[201];
    int mini, mind = INF;
    for(int i = 1; i <= K; i++) {
        bool isCycle = true, isSimple = true, isAvi = true;
        fill(vis, vis + 201, 0);
        int n, s, dis = 0;
        scanf("%d%d", &n, &s);
        u = s;
        for(int j = 1; j < n - 1; j++) {
            scanf("%d", &v);
            if(G[u][v] == INF || !isAvi) {
                isAvi = false;
                continue;
            } else {
                dis += G[u][v];
                if(vis[v]) isSimple = false;
                vis[v] = true;
            }
            u = v;
        }
        scanf("%d", &v);
        vis[v] = true;
        dis += G[u][v];
        for(int j = 1; j <= N; j++)
            if(vis[j] == false) {
                isCycle = false;
                break;
            }
        if(isAvi)
            printf("Path %d: %d ", i, dis);
        else
            printf("Path %d: NA ", i);
        if(s != v) isCycle = false;
        if(isAvi && isCycle && dis < mind) {
            mini = i;
            mind = dis;
        }
        if(!isCycle || !isAvi)
            printf("(Not a TS cycle)\n");
        else if(isSimple)
            printf("(TS simple cycle)\n");
        else
            printf("(TS cycle)\n");
    }
    printf("Shortest Dist(%d) = %d\n", mini, mind);
    return 0;
}

