#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int v, len, time;
};

const int INF = 0x3fffffff;
int N, M, d1[501], d2[501], pre[501];
vector<Node> g[501];  // 用矩阵内存超了。。。。被迫用邻接表

void Dijkstra1(int s) {
    fill(d1, d1 + 501, INF);
    fill(d2, d2 + 501, INF);
    d1[s] = 0;
    d2[s] = 0;
    bool vis[501] = {0};
    for(int i = 0; i < N; i++) {
        int u = -1, mind = INF;
        for(int j = 1; j <= N; j++) {
            if(!vis[j] && d1[j] < mind) {
                u = j;
                mind = d1[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < g[u].size(); j++) {
            int v = g[u][j].v;
            if(!vis[v]) {
                if(g[u][j].len + d1[u] < d1[v]) {
                    d1[v] = g[u][j].len + d1[u];
                    d2[v] = g[u][j].time + d2[u];
                    pre[v] = u;
                } else if(g[u][j].len + d1[u] == d1[v] && g[u][j].time + d2[u] < d2[v]) {
                    d2[v] = g[u][j].time + d2[u];
                    pre[v] = u;
                }
            }
        }
    }
}

void Dijkstra2(int s) {
    fill(d2, d2 + 501, INF);
    fill(d1, d1 + 501, 0);
    d2[s] = 0;
    bool vis[501] = {0};
    for(int i = 0; i < N; i++) {
        int u = -1, mind = INF;
        for(int j = 1; j <= N; j++) {
            if(!vis[j] && d2[j] < mind) {
                u = j;
                mind = d2[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < g[u].size(); j++) {
            int v = g[u][j].v;
            if(!vis[v]) {
                if(g[u][j].time + d2[u] < d2[v]) {
                    d2[v] = g[u][j].time + d2[u];
                    d1[v] = d1[u] + 1;
                    pre[v] = u;
                } else if(g[u][j].time + d2[u] == d2[v] && d1[u] + 1 < d1[v]) {
                    d1[v] = 1 + d1[u];
                    pre[v] = u;
                }
            }
        }
    }
}

int main() {
    int v1, v2, onew, len, time, D, T;
    vector<int> p1, p2;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d%d%d", &v1, &v2, &onew, &len, &time);
        struct Node t;
        t.v = v2;
        t.len = len;
        t.time = time;
        g[v1].push_back(t);
        if(!onew) {
            t.v = v1;
            g[v2].push_back(t);
        }
    }
    scanf("%d%d", &v1, &v2);
    Dijkstra1(v1);
    D = d1[v2];
    for(int i = v2; i != v1; i = pre[i])
        p1.push_back(i);
    Dijkstra2(v1);
    T = d2[v2];
    for(int i = v2; i != v1; i = pre[i])
        p2.push_back(i);
    if(p1 == p2) {
        printf("Distance = %d; Time = %d: %d", D, T, v1);
        for(int i = p1.size() - 1; i >= 0; i--)
            printf(" -> %d", p1[i]);
    } else {
        printf("Distance = %d: %d", D, v1);
        for(int i = p1.size() - 1; i >= 0; i--)
            printf(" -> %d", p1[i]);
        printf("\nTime = %d: %d", T, v1);
        for(int i = p2.size() - 1; i >= 0; i--)
            printf(" -> %d", p2[i]);
    }
    return 0;
}

