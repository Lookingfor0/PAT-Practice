#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100000];
int N;
bool re[100000] = {0};
double P, r, sum = 0.0;

void dfs(int s, double p) {
    if(re[s]) {
        sum += p * v[s][0];
        return;
    }
    for(int i = 0; i < v[s].size(); i++) dfs(v[s][i], p * r);
}

int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    r = 1 + r / 100;
    for(int i = 0; i < N; i++) {
        int t, k;
        scanf("%d%d", &k, &t);
        v[i].push_back(t);
        if(k) {
            for(int j = 1; j < k; j++) {
                scanf("%d", &t);
                v[i].push_back(t);
            }
        } else re[i] = true;
    }
    dfs(0, P);
    printf("%.1lf", sum);
    return 0;
}

