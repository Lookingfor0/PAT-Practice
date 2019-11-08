// 先简单DFS求出所有最短路径，然后DFS判断第二优先条件
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 500;
const int INF = 0x3fffffff;

int N, M, S, D, Dis[MAXN][MAXN], Cost[MAXN][MAXN], d[MAXN], optcost = INF;
vector<int> path, tpath, pre[MAXN];

void Dijkstra() {
    fill(d, d + MAXN, INF);
    d[S] = 0;
    bool vis[MAXN] = {0};
    for(int i = 0; i < N; i++) {
        int u = -1, mind = INF;
        for(int j = 0; j < N; j++) {
            if(!vis[j] && d[j] < mind) {
                u = j;
                mind = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && Dis[u][v] != INF) {
                if(d[v] > d[u] + Dis[u][v]) {
                    d[v] = d[u] + Dis[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[v] == d[u] + Dis[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v, int cost) {
    tpath.push_back(v);
    if(v == S) {
        if(cost < optcost) {
            optcost = cost;
            path = tpath;
        }
    }else {
        for(int i = 0; i < pre[v].size(); i++)
            DFS(pre[v][i], cost + Cost[v][pre[v][i]]);  // 这里注意不要写成 Cost[v][i]
    }
    tpath.pop_back();
}

int main() {
    int c1, c2, dd, cc;
    scanf("%d%d%d%d", &N, &M, &S, &D);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Dis[i][j] = Dis[j][i] = INF;  // Cost 并不需要初始化
    for(int i = 0; i < M; i++) {  // 读入数据
        scanf("%d%d%d%d", &c1, &c2, &dd, &cc);
        Dis[c1][c2] = Dis[c2][c1] = dd;
        Cost[c1][c2] = Cost[c2][c1] = cc;
    }
    Dijkstra();
    DFS(D, 0);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d\n", d[D], optcost);
    return 0;
}

