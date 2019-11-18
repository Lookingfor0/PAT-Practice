#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct Node *Tree;
struct Node {
    int d;
    Tree l, r;
};

int N, post[30], in[30];

Tree BiuldTree(int pe, int is, int ie) {
    if(is > ie) return NULL;
    Tree r = new Node;
    r->d = post[pe];
    int ir;
    for(ir = is; ir <= ie; ir++)
        if(in[ir] == post[pe]) break;
    r->l = BiuldTree(pe - ie + ir - 1, is, ir - 1);
    r->r = BiuldTree(pe - 1, ir + 1, ie);
    return r;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]);
    Tree root = BiuldTree(N - 1, 0, N - 1);
    bool zig = true;
    stack<Tree> s;
    vector<int> ans;
    s.push(root);
    while(!s.empty()) {
        stack<Tree> temp;
        while(!s.empty()) {
            Tree t = s.top();
            s.pop();
            ans.push_back(t->d);
            if(zig) {
                if(t->r) temp.push(t->r);
                if(t->l) temp.push(t->l);
            } else {
                if(t->l) temp.push(t->l);
                if(t->r) temp.push(t->r);
            }
        }
        zig = !zig;
        s = temp;
    }
    for(int i = 0; i < ans.size() - 1; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size() - 1]);
    return 0;
}

