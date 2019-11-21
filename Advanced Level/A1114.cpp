#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Data {
    int est, are;
}data[10000];

struct family {
    int id, mb, est, are;
    double aest, aare;
};

int N, s[10000];
bool flag[10000] = {0};

bool cmp(family A, family B) {
    if(A.aare == B.aare) return A.id < B.id;
    else return A.aare > B.aare;
}

int Find(int a) {
    if(s[a] < 0) return a;
    else return s[a] = Find(s[a]);
}

void Union(int a, int b) {
    int ra = Find(a), rb = Find(b);
    if(ra < rb) {
        s[ra] += s[rb];
        s[rb] = ra;
    } else if(ra > rb) {
        s[rb] += s[ra];
        s[ra] = rb;
    }
}

int main() {
    scanf("%d", &N);
    fill(s, s + 10000, -1);
    for(int i = 0; i < N; i++) {
        int id, fa, ma, k, des;
        scanf("%d%d%d%d", &id, &fa, &ma, &k);
        flag[id] = true;
        if(fa != -1) { Union(id, fa); flag[fa] = true; }
        if(ma != -1) { Union(id, ma); flag[ma] = true; }
        while(k--) {
            scanf("%d", &des);
            flag[des] = true;
            Union(id, des);
        }
        scanf("%d%d", &(data[id].est), &(data[id].are));
    }
    unordered_map<int, struct family> fml;
    for(int i = 0; i < 10000; i++)  // 这里要写10000，不能写N
        if(flag[i] && s[i] < 0) {
            struct family f;
            f.id = i;
            f.are = data[i].are;
            f.est = data[i].est;
            f.mb = -s[i];
            fml[i] = f;
        }
    for(int i = 0; i < 10000; i++)
        if(flag[i] && s[i] >= 0) {
            int anc = Find(i);
            fml[anc].est += data[i].est;
            fml[anc].are += data[i].are;
        }
    vector<struct family> ans;
    for(auto it = fml.begin(); it != fml.end(); it++) {
        it->second.aest = it->second.est / (double)it->second.mb;
        it->second.aare = it->second.are / (double)it->second.mb;
        ans.push_back(it->second);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].mb, ans[i].aest, ans[i].aare);
    return 0;
}

