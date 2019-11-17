#include <iostream>
#include <vector>
#include <cmath>

#define MAX(a, b) ((a) > (b))?a:b;

using namespace std;


typedef struct Node *Tree;
struct Node {
    int key, num;  // num为当前节点到根节点的黑节点个数
    Tree l, r;
};

Tree BiuldTree(int pre[], int s, int e) {
    if(s > e) return NULL;
    Tree root = (Tree)malloc(sizeof(Node));
    root->key = pre[s];
    int i = s + 1;
    while(i <= e && abs(pre[i]) <= abs(pre[s]))
        i++;
    root->l  = BiuldTree(pre, s + 1, i - 1);
    root->r  = BiuldTree(pre, i, e);
    return root;
}

void FreeTree(Tree root) {
    if(root == NULL) return;
    FreeTree(root->l);
    FreeTree(root->r);
    free(root);
}

bool DFS1(Tree node) {
    if(node == NULL) return true;
    Tree l = node->l, r = node->r;
    if(node->key < 0 && ((l && l->key < 0) || (r && r->key < 0)))
        return false;
    return DFS1(l) && DFS1(r);
}

int DFS2(Tree node) {
    if(node == NULL) return 0;
    int m = MAX(DFS2(node->l), DFS2(node->r));
    if(node->key > 0) node->num = m + 1;
    else node->num = m;
    return node->num;
}

bool DFS3(Tree node) {
    if(node == NULL) return true;
    int ln = node->l == NULL ? 0 : node->l->num, rn = node->r == NULL ? 0 : node->r->num;
    return DFS3(node->l) && DFS3(node->r) && ln == rn;
}

bool Judge(Tree root) {
    if(root->key < 0) return false;
    DFS2(root);
    return DFS1(root) && DFS3(root);
}

int main() {
    int K, N, pre[30];
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &pre[i]);
        Tree root = BiuldTree(pre, 0, N - 1);
        printf("%s\n", Judge(root) ? "Yes" : "No");
        FreeTree(root);
    }
    return 0;
}

