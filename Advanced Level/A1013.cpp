// BFS就行，破坏的城市提前把vis设为true就行了
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, K, vis[1001] = {0};
    vector<int> G[1001];
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < K; i++) {
        for(int j = 1; j <= N; j++) vis[j] = false;
        int c, cnt;
        scanf("%d", &c);
        vis[c] = true;
        queue<int> q;
        cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(!vis[j]) {
                q.push(j);
                vis[j] = true;
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for(int k = 0; k < G[u].size(); k++) {
                        int v = G[u][k];
                        if(!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}

