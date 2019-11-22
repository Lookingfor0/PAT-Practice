#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int l, r;
} a[20];

bool isComplete = false;
int last;

void BFS(int root) {
    queue<int> level;
    bool noChild = false;
    isComplete = true;
    level.push(root);
    while(!level.empty()) {
        last = level.front();
        level.pop();
        if(a[last].l != -1) {
            level.push(a[last].l);
            if(noChild) isComplete = false;
        }
        else
            noChild = true;
        if(a[last].r != -1) {
            level.push(a[last].r);
            if(noChild) isComplete = false;
        }
        else
            noChild = true;
    }
}

int main() {
    int N, root = 0;
    scanf("%d", &N);
    bool flag[20] = {0};
    for(int i = 0; i < N; i++) {  // 这里输入时不能用char，因为下标可能大于9
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            flag[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            flag[stoi(r)] = 1;
        }
    }
    while(flag[root]) root++;
    BFS(root);
    if(isComplete)
        printf("YES %d", last);
    else
        printf("NO %d", root);
    return 0;
}

