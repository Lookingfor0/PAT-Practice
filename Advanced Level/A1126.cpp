#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> G[501];

bool IsConnected() {
    bool vis[501] = {0};
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++) {
            if(!vis[G[u][i]]) {
                q.push(G[u][i]);
                vis[G[u][i]] = true;
            }
        }
    }
    for(int i = 1; i <= N; i++)
        if(vis[i] == false) return false;
    return true;
}

int main() {
    int u, v, odd = 0;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i < N; i++)
        printf("%d ", G[i].size());
    printf("%d\n", G[N].size());
    for(int i = 1; i <= N; i++)
        if(G[i].size() % 2 == 1) odd++;
    if(!IsConnected() || (odd != 0 && odd != 2)) printf("Non-Eulerian\n");
    else if(odd == 2) printf("Semi-Eulerian\n");
    else printf("Eulerian\n");
    return 0;
}

