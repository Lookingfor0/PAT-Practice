#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int l, r;
}n[10];

int N;
vector<int> in;

void LevelOrder(int root) {
    queue<int> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()) {
        int t = q.front();
        ans.push_back(t);
        q.pop();
        if(n[t].r != -1) q.push(n[t].r);
        if(n[t].l != -1) q.push(n[t].l);
    }
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
}


void InvertInOrder(int root) {
    if(n[root].r != -1) InvertInOrder(n[root].r);
    in.push_back(root);
    if(n[root].l != -1) InvertInOrder(n[root].l);
}

int main() {
    scanf("%d", &N);
    bool flag[10] = {0};
    int root;
    for(int i = 0; i < N; i++) {
        char l, r;
        getchar();
        scanf("%c", &l);
        getchar();
        scanf("%c", &r);
        if(l == '-')
            n[i].l = -1;
        else {
            n[i].l = l - '0';
            flag[n[i].l] = true;
        }
        if(r == '-')
            n[i].r = -1;
        else {
            n[i].r = r - '0';
            flag[n[i].r] = true;
        }
    }
    root = 0;
    while(flag[root]) root++;
    LevelOrder(root);
    InvertInOrder(root);
    printf("\n%d", in[0]);
    for(int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    return 0;
}

