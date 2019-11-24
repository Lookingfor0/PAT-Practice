#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int s[1001];

int Find(int A) {
    if(s[A] < 0) return A;
    else return s[A] = Find(s[A]);
}

void Union(int A, int B) {
    int fa = Find(A), fb = Find(B);
    if(fa == fb) return;
    else if(s[fa] < s[fb]) {
        s[fa] += s[fb];
        s[fb] = fa;
    } else {
        s[fb] += s[fa];
        s[fa] = fb;
    }
}

int main() {
    int N;
    memset(s, -1, sizeof(s));
    scanf("%d", &N);
    vector<int> h[1001], ans;
    for(int i = 1; i <= N; i++) {
        int K, th;
        scanf("%d:", &K);
        while(K--) {
            scanf("%d", &th);
            h[th].push_back(i);
        }
    }
    for(int i = 1; i <= 1000; i++) {  // 这里要写1000，因为hobby的范围和N不一样
        if(h[i].size() > 1) {
            int A = h[i][0];
            for(int j = 1; j < h[i].size(); j++)
                Union(A, h[i][j]);
        }
    }
    for(int i = 1; i <= N; i++)
        if(s[i] < 0) ans.push_back(-s[i]);
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n%d", ans.size(), ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}

