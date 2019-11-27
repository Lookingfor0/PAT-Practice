#include <iostream>
#include <queue>

using namespace std;

int g[1300][130][80] = {0}, M, N, L, T;
bool vis[1300][130][80] = {0};

struct Node {
    int x, y, z;
};

void PUSH(queue<Node> &q, int i, int j, int k) {
    q.push(Node({i, j, k}));
    vis[i][j][k] = true;
}

int bfs(int i, int j, int k) {
    int cnt = 0;
    queue<Node> q;
    PUSH(q, i, j, k);
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        cnt++;
        i = node.x;
        j = node.y;
        k = node.z;
        if(i + 1 < M && !vis[i + 1][j][k] && g[i + 1][j][k] == 1) PUSH(q, i + 1, j, k);
        if(i - 1 >= 0 && !vis[i - 1][j][k] && g[i - 1][j][k] == 1) PUSH(q, i - 1, j, k);
        if(j + 1 < N && !vis[i][j + 1][k] && g[i][j + 1][k] == 1) PUSH(q, i, j + 1, k);
        if(j - 1 >= 0 && !vis[i][j - 1][k] && g[i][j - 1][k] == 1) PUSH(q, i, j - 1, k);
        if(k + 1 < L && !vis[i][j][k + 1] && g[i][j][k + 1] == 1) PUSH(q, i, j, k + 1);
        if(k - 1 >= 0 && !vis[i][j][k - 1] && g[i][j][k - 1] == 1) PUSH(q, i, j, k - 1);
    }
    return cnt;
}

//int dfs(int i, int j, int k) {  // 爆栈。。。。
//    int cnt = 0;
//    vis[i][j][k] = true;
//    if(g[i][j][k] == 0) return cnt;
//    cnt++;
//    if(i + 1 < M && !vis[i + 1][j][k] && g[i + 1][j][k] == 1) cnt += bfs(i + 1, j, k);
//    if(i - 1 >= 0 && !vis[i - 1][j][k] && g[i - 1][j][k] == 1) cnt += bfs(i - 1, j, k);
//    if(j + 1 < N && !vis[i][j + 1][k] && g[i][j + 1][k] == 1) cnt += bfs(i, j + 1, k);
//    if(j - 1 >= 0 && !vis[i][j - 1][k] && g[i][j - 1][k] == 1) cnt += bfs(i, j - 1, k);
//    if(k + 1 < L && !vis[i][j][k + 1] && g[i][j][k + 1] == 1) cnt += bfs(i, j, k + 1);
//    if(k - 1 >= 0 && !vis[i][j][k - 1] && g[i][j][k - 1] == 1) cnt += bfs(i, j, k - 1);
//    return cnt;
//}

int main() {
    scanf("%d%d%d%d", &M, &N, &L, &T);
    int sum = 0;
    for(int k = 0; k < L; k++)
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &g[i][j][k]);
    for(int k = 0; k < L; k++)
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                if(!vis[i][j][k] && g[i][j][k] == 1) {
                    int t = bfs(i, j, k);
                    if(t >= T) sum += t;
                }
    printf("%d\n", sum);
    return 0;
}

