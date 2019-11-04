#include <cstdio>
#include <queue>

using namespace std;

bool G[1001][1001] = { 0 };

int BFS(int V, int L) {
    queue<int> q;
    bool vis[1001] = { 0 };
    int level = 0, last = V, v, t, c = -1;
    q.push(V);
    vis[V] = true;
    while(!q.empty() && level <= L) {
        v = q.front();
        q.pop();
        c++;
        for(int i = 1; i < 1001; i++) {
            if(!vis[i] && G[v][i]) {
                q.push(i);
                t = i;
                vis[i] = true;
            }
        }
        if(v == last) { level++; last = t;}
    }
    return c;
}

int main() {
    int N, L, K, follown, followed;
    scanf("%d%d", &N, &L);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &follown);
        while(follown--) {
            scanf("%d", &followed);
            G[followed][i] = true;
        }
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &followed);
        printf("%d\n", BFS(followed, L));
    }
    return 0;
}

