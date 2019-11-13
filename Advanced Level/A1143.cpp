#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, pre[10001], u, v;
    unordered_map<int, bool> m;
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
        m[pre[i]] = true;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        if(!m[u]) {
            if(m[v])
                printf("ERROR: %d is not found.\n", u);
            else
                printf("ERROR: %d and %d are not found.\n", u, v);
        } else if(!m[v]) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            int a;
            for(int j = 0; j < N; j++) {
                a = pre[j];
                if((a <= u && a >= v) || (a >= u && a <= v)) break;
            }
            if(a == u || a == v)
                printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
}

