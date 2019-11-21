#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node *Tree;
struct Node {
    int d;
    Tree l, r;
};

Tree Insert(Tree T, int x) {
    if(T == NULL) {
        T = (Tree)malloc(sizeof(struct Node));
        T->d = x;
        T->l = T->r = NULL;
    } else if(T->d >= x)
        T->l = Insert(T->l, x);
    else
        T->r = Insert(T->r, x);
    return T;
}

void BFS(Tree T, vector<int> &level, int &maxL) {
    maxL = 0;
    queue<Tree> q, temp;
    q.push(T);
    while(!q.empty()) {
        Tree cur = q.front();
        q.pop();
        level[maxL]++;
        if(cur->l) temp.push(cur->l);
        if(cur->r) temp.push(cur->r);
        if(q.empty()) {
            maxL++;
            swap(q, temp);  // 清空temp
        }
    }
}

int main() {
    int N;
    Tree T = NULL;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        T = Insert(T, t);
    }
    vector<int> level(1010);
    int maxL;
    BFS(T, level, maxL);
    int a = maxL > 0 ? level[maxL - 1] : 0, b = maxL > 1 ? level[maxL - 2] : 0;  // 要考虑如果不足两层的情况，用容器的话没关系，而数组就会错误
    printf("%d + %d = %d", a, b, a + b);
    return 0;
}

