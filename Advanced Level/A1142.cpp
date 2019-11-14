#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int Nv, Ne, M, k, u, v, cli[201];
    bool G[201][201] = {0}, isCli, isMax;
    unordered_map<int, bool> m;
    scanf("%d%d", &Nv, &Ne);
    for(int i = 0; i < Ne; i++) {
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = true;
    }
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &k);
        m.clear();
        for(int i = 0; i < k; i++) {
            scanf("%d", &cli[i]);
            m[cli[i]] = true;
        }
        isCli = true;
        for(int i = 0; isCli && i < k - 1; i++) {
            for(int j = i + 1; j < k; j++) {
                if(!G[cli[i]][cli[j]]) {
                    isCli = false;
                    break;
                }
            }
        }
        isMax = true;
        for(int i = 1; isMax && i <= Nv; i++) {
            if(!m[i]) {
                int cnt = 0;
                for(int j = 0; j < k; j++)
                    if(G[i][cli[j]]) cnt++;
                if(cnt == k) {
                    isMax = false;
                    break;
                }
            }
        }
        if(isCli)
            printf("%s\n", isMax ? "Yes" : "Not Maximal");
        else
            printf("Not a Clique\n");
    }
    return 0;
}

