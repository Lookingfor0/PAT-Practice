#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int addr, data, next;
}v[100000];

int main() {
    int N, head, K, t, p;
    vector<int> ans;
    scanf("%d%d%d", &head, &N, &K);
    if(head == -1 || !N) return 0;
    for(int i = 0; i < N; i++) {
        int addr;
        scanf("%d", &addr);
        v[addr].addr = addr;
        scanf("%d%d", &v[addr].data, &v[addr].next);
    }
    t = head;
    while(t != -1) {
        ans.push_back(t);
        t = v[t].next;
    }
    for(p = 0; p + K <= ans.size(); p += K) reverse(ans.begin() + p, ans.begin() + p + K);
    for(int i = 0; i < ans.size(); i++) {
        if(i != ans.size() - 1) printf("%05d %d %05d\n", ans[i], v[ans[i]].data, ans[i + 1]);
        else printf("%05d %d -1\n", ans[i], v[ans[i]].data);
    }
    return 0;
}

