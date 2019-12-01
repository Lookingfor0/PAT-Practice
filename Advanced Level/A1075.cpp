#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct STU {
    int sub[6], total, perf;
    bool has_sub[6], has_comp[6];
}stu[10001];

int N, K, M, score[6];
bool vis[10001] = {0};
vector<int> ans;

bool cmp1(int a, int b) {
    if(stu[a].total != stu[b].total) return stu[a].total > stu[b].total;
    else if(stu[a].perf != stu[b].perf) return stu[a].perf > stu[b].perf;
    else return a < b;
}

int main() {
    scanf("%d%d%d", &N, &K, &M);
    for(int i = 1; i <= K; i++) scanf("%d", &score[i]);
    for(int i = 0; i < M; i++) {
        int id, pid, sc;
        scanf("%d%d%d", &id, &pid, &sc);
        stu[id].has_sub[pid] = true;  // 只要提交了而且进入排名，即使那道题没过编译（-1分），输出的时候是 0 分而不是 -1
        if(sc >= 0) {
            stu[id].has_comp[pid] = true;
            if(sc > stu[id].sub[pid]) {
                stu[id].total += sc - stu[id].sub[pid];
                stu[id].sub[pid] = sc;
                if(sc == score[pid]) stu[id].perf++;
            }
            if(!vis[id]) {
                vis[id] = true;
                ans.push_back(id);
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp1);
    int r;
    for(int i = 0; i < ans.size(); i++) {
        if(i == 0 || stu[ans[i]].total != stu[ans[i - 1]].total) r = i + 1;
        printf("%d %05d %d", r, ans[i], stu[ans[i]].total);
        for(int j = 1; j <= K; j++) {
            if(stu[ans[i]].has_sub[j]) printf(" %d", stu[ans[i]].sub[j]);
            else printf(" -");
        }
        printf("\n");
    }
    return 0;
}

