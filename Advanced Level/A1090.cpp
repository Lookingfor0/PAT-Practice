#include <iostream>
#include <vector>

using namespace std;

int N, root, hn;
double P, r, hp = 0;
vector<int> a[100000];

void dfs(int root, double p) {
    if(a[root].size() == 0) {
        if(p > hp) {
            hn = 1;
            hp = p;
        } else if(p == hp)
            hn++;
    } else {
        for(int i = 0; i < a[root].size(); i++)
            dfs(a[root][i], p * (1 + r / 100));
    }
}

int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    for(int i = 0; i < N; i++) {
        int sup;
        scanf("%d", &sup);
        if(sup == -1)
            root = i;
        else
            a[sup].push_back(i);
    }
    dfs(root, P);
    printf("%.2f %d\n", hp, hn);
    return 0;
}

