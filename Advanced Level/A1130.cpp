#include <iostream>
using namespace std;
struct node {
    string data;
    int l, r;
}a[100];
string dfs(int root) {
    if(a[root].l == -1 && a[root].r == -1) return a[root].data;
    if(a[root].l == -1 && a[root].r != -1)  return "(" +  a[root].data + dfs(a[root].r) + ")";
    if(a[root].l != -1 && a[root].r != -1) return "(" +  dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
}
int main() {
    int have[100] = {0}, n, root = 1;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if(a[i].l != -1) have[a[i].l] = 1;
        if(a[i].r != -1) have[a[i].r] = 1;
    }
    while(have[root] == 1) root++;
    string ans = dfs(root);
    if(ans[0] == '(') ans = ans.substr(1,ans.size()-2);
    cout << ans;
    return 0;
}

// my version
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    int l, r;
}nodes[21];

void InfixExp(int head) {
    if(nodes[head].l != -1) {
        bool flag = nodes[nodes[head].l].l != -1 || nodes[nodes[head].l].r != -1;
        if(flag) printf("(");
        InfixExp(nodes[head].l);
        if(flag) printf(")");
    }
    printf("%s", nodes[head].data.c_str());
    if(nodes[head].r != -1) {
        bool flag = nodes[nodes[head].r].l != -1 || nodes[nodes[head].r].r != -1;
        if(flag) printf("(");
        InfixExp(nodes[head].r);
        if(flag) printf(")");
    }
}

int main() {
    int N, head;
    bool vis[21];
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        cin >> nodes[i].data >> nodes[i].l >> nodes[i].r;
        if(nodes[i].l != -1) vis[nodes[i].l] = true;
        if(nodes[i].r != -1) vis[nodes[i].r] = true;
    }
    for(int i = 1; i <= N; i++)
        if(vis[i] == false) {
            head = i;
            break;
        }
    InfixExp(head);
    return 0;
}

