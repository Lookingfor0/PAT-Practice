#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

unordered_map<string, int> cti;
unordered_map<int, string> itc;
int C[200][200], H[200] = {0}, d1[200], d2[200] = {0}, d3[200] = {0}, N, K, st, ed, pre[200], rnum[200] = {0};  // d3 表示当前经过的城市数
string beginc;
vector<string> ans;

void Dikjstra(int s) {
    bool vis[200] = {0};
    fill(d1, d1 + N, INF);
    fill(pre, pre + N, -1);
    rnum[s] = 1;
    d1[s] = 0;
    for(int i = 0; i < N; i++) {
        int u = -1, mind = INF;
        for(int j = 0; j < N; j++) {
            if(!vis[j] && d1[j] < mind) {
                u = j;
                mind = d1[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && C[u][v] != INF) {
                if(d1[v] > d1[u] + C[u][v]) {
                    d1[v] = d1[u] + C[u][v];
                    d2[v] = d2[u] + H[v];
                    d3[v] = d3[u] + 1;
                    rnum[v] = rnum[u];
                    pre[v] = u;
                } else if(d1[v] == d1[u] + C[u][v]) {
                    rnum[v] += rnum[u];  // 注意这句的位置
                    if(d2[v] < d2[u] + H[v]) {
                        d2[v] = d2[u] + H[v];
                        d3[v] = d3[u] + 1;
                        pre[v] = u;
                    } else if(d2[v] == d2[u] + H[v] && d3[v] > d3[u] + 1) {
                        d3[v] = d3[u] + 1;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> K >> beginc;
    cti[beginc] = 0;
    itc[0] = beginc;
    fill(C[0], C[0] + 200 * 200, INF);
    for(int i = 1; i < N; i++) {
        string city;
        int hap;
        cin >> city >> hap;
        cti[city] = i;
        itc[i] = city;
        H[i] = hap;
    }
    for(int i = 0; i < K; i++) {
        string s1, s2;
        int cost;
        cin >> s1 >> s2 >> cost;
        int c1 = cti[s1], c2 = cti[s2];
        C[c1][c2] = C[c2][c1] = cost;
    }
    st = 0;
    ed = cti["ROM"];
    Dikjstra(st);
    for(int i = 0, p = ed; p != st; i++, p = pre[p])
        ans.push_back(itc[p]);
    ans.push_back(itc[st]);
    printf("%d %d %d %d\n", rnum[ed], d1[ed], d2[ed], d2[ed] / d3[ed]);
    for(int i = ans.size() - 1; i >= 0; i--) {
        printf("%s", ans[i].c_str());
        if(i != 0) printf("->");
    }
    return 0;
}

