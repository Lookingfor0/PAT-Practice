#include <iostream>
#include <unordered_map>

using namespace std;

int pre[10001], in[10001], iu, iv, u, v;
unordered_map<int, int> pos;

void LCA(int ins, int ine, int pres) {
    // u和v都存在
    if(ins >= ine) return;
    int root = pos[pre[pres]];
//    if(iu == iv)
//        printf("LCA of %d and %d is %d.\n", u, v, u);
    if(iu == root)  // 这里很坑，如果u和v相等还是按这种方式输出，注意理解题目
        printf("%d is an ancestor of %d.\n", in[iu], in[iv]);
    else if(iv == root)
        printf("%d is an ancestor of %d.\n", in[iv], in[iu]);
    else if((iu < root && iv > root) || (iu > root && iv < root))
        printf("LCA of %d and %d is %d.\n", u, v, in[root]);
    else if(iu < root && iv < root)
            LCA(ins, root, pres + 1);
    else
            LCA(root + 1, ine, pres + root - ins + 1);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;  // 如果之后再查找会超时
    }
    for(int i = 1; i <= M; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &u, &v);
        iu = pos[u];
        iv = pos[v];
        if(iu == 0) {
            if(iv == 0)
                printf("ERROR: %d and %d are not found.\n", u, v);
            else
                printf("ERROR: %d is not found.\n", u);
        } else if(iv == 0)
            printf("ERROR: %d is not found.\n", v);
        else
            LCA(1, M + 1, 1);
    }
    return 0;
}

