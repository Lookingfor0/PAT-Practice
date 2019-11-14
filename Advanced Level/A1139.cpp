// 有三个测试点未通过，不知道BUG在哪

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, bool> gender;
unordered_map<int, vector<int>> G;  // 邻接表

bool isFriend(int a, int b) {
    for(auto s : G[a])
        if(s == b) return true;
    return false;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int N, M, K;
    scanf("%d%d", &N, &M);
    string a, b;
    int aa, bb;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        aa = abs(stoi(a));
        bb = abs(stoi(b));
        if(a[0] == '-') gender[aa] = true;
        if(b[0] == '-') gender[bb] = true;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    scanf("%d", &K);
    vector<pair<int, int>> ans;
    while(K--) {
        ans.clear();
        cin >> aa >> bb;
        aa = abs(aa);
        bb = abs(bb);
        for(auto cc : G[aa]) {
            for(auto dd : G[bb]) {
                if(cc != dd && cc != bb && dd != aa && isFriend(cc, dd) && gender[aa] == gender[cc] && gender[bb] == gender[dd])
                    ans.push_back({cc, dd});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(auto s : ans)
            printf("%d %d\n", s.first, s.second);
    }
    return 0;
}


