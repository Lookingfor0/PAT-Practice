#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct app{
    int id, ge, gi, pref[5], adi;
    double gf;
}a[40000];

int N, M, K, quota[100];
set<int> addm[100];

bool cmp1(app A, app B) {
    if(A.gf == B.gf) return A.ge > B.ge;
    else return A.gf > B.gf;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < M; i++) scanf("%d", &quota[i]);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &a[i].ge, &a[i].gi);
        a[i].gf = (a[i].ge + a[i].gi) / 2;
        a[i].id = i;
        for(int j = 0; j < K; j++) scanf("%d", &a[i].pref[j]);
    }
    sort(a, a + N, cmp1);
    for(int i = 0; i < N; i++) {
        bool samer = (a[i].gf == a[i - 1].gf && a[i].ge == a[i - 1].ge) ? true : false;
        for(int j = 0; j < K; j++) {
            int s = a[i].pref[j];
            if(addm[s].size() < quota[s] || (samer && s == a[i - 1].adi)) {
                a[i].adi = s;
                addm[a[i].adi].insert(a[i].id);
                break;
            }
        }
    }
    for(int i = 0; i < M; i++) {
        for(auto it = addm[i].begin(); it != addm[i].end(); it++) {
            if(it != addm[i].begin()) printf(" ");
            printf("%d", *it);
        }
        printf("\n");
    }
    return 0;
}

