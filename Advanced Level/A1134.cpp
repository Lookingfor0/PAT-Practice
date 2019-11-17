#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    vector<Edge> e;
    set<int> ves;
    int N, M, K, u, v;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        e.push_back(Edge({u, v}));
    }
    scanf("%d", &K);
    while(K--) {
        int nv;
        scanf("%d", &nv);
        ves.clear();
        for(int i = 0; i < nv; i++) {
            scanf("%d", &v);
            ves.insert(v);
        }
        bool flag = true;
        for(int i = 0; i < e.size(); i++) {
            if(ves.find(e[i].u) == ves.end() && ves.find(e[i].v) == ves.end()) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}

