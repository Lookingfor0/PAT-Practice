#include <iostream>
#include <vector>

using namespace std;

int N, M, ln[101] = {0}, maxl = 0, maxn = 0;
vector<int> v[100];

void dfs(int root, int level) {
    ln[level]++;
    if(ln[level] > maxn) {
        maxn = ln[level];
        maxl = level;
    }
    for(int i = 0; i < v[root].size(); i++)
        dfs(v[root][i], level + 1);
}

int main() {
    bool flag[101] = {false};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        int id, k, t;
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            v[id].push_back(t);
            flag[t] = true;
        }
    }
    int r = 1;
    while(flag[r]) r++;
    dfs(r, 1);
    printf("%d %d\n", maxn, maxl);
    return 0;
}

