#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int d, l, r;
}tree[100];

int N, n, index = 0;
vector<int> v;

void InOrder(int root) {
    if(tree[root].l != -1) InOrder(tree[root].l);
    tree[root].d = v[index++];
    if(tree[root].r != -1) InOrder(tree[root].r);
}

void LevelOrder() {
    queue<int> q;
    vector<int> ans;
    q.push(0);
    while(!q.empty()) {
        auto cur = tree[q.front()];
        q.pop();
        ans.push_back(cur.d);
        if(cur.l != -1) q.push(cur.l);
        if(cur.r != -1) q.push(cur.r);
    }
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &tree[i].l, &tree[i].r);
    for(int i = 0; i < N; i++) {
        scanf("%d", &n);
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    InOrder(0);
    LevelOrder();
    return 0;
}

