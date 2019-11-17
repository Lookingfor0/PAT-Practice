#include <iostream>
#include <unordered_map>
#include <vector>

#define INF 0x3fffffff

using namespace std;

bool vis[10000];
unordered_map<int, int> line;
vector<int> path, tempPath, G[10000];
int st, ed, minStop, minTrans;

void DFS(int s, int scnt, int tcnt) {
    if(scnt > minStop) return;
    tempPath.push_back(s);
    if(s == ed) {
        if(scnt < minStop) {
            minStop = scnt;
            minTrans = tcnt;
            path = tempPath;
        } else if(scnt == minStop && tcnt < minTrans) {
            minTrans = tcnt;
            path = tempPath;
        }
    } else {
        int preL = (s == st) ? 0 : line[s * 10000 + tempPath[tempPath.size() - 2]];
        for(int i = 0; i < G[s].size(); i++) {
            if(!vis[G[s][i]]) {
                vis[G[s][i]] = true;
                int a = (line[s * 10000 + G[s][i]] != preL)?1:0;
                DFS(G[s][i], scnt + 1, tcnt + a);
                vis[G[s][i]] = false;
            }
        }
    }
    tempPath.pop_back();
}

int main() {
    int N, M, K;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &M);
        int u, v;
        scanf("%d", &u);
        while(--M) {
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
            line[u * 10000 + v] = i;
            line[v * 10000 + u] = i;
            u = v;
        }
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d%d", &st, &ed);
        minStop = minTrans = INF;
        vis[st] = true;
        DFS(st, 0, 0);
        vis[st] = false;
        printf("%d\n", path.size() - 1);
        int u = st, v = path[1], L, i = 1;
        while(i < path.size()) {
            L = line[u * 10000 + v];
            printf("Take Line#%d from %04d to ", L, u);  // 这个04d不要忘了
            for(u = v, i++; i < path.size(); u = v, i++) {
                v = path[i];
                if(line[u * 10000 + v] != L) break;
            }
            printf("%04d.\n", u);
        }
    }
    return 0;
}

