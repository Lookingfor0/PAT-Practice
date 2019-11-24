#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int g[101][101], N, a[10000], i, r, c, m, n;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", a + i);
    sort(a, a + N, greater<int>());
    for(m = sqrt(N); m <= N; m++) {
        n = N / m;
        if(m * n == N && m >= n) break;
    }
    i = 0;
    for(int j = 0; i < N; j++) {
        r = c = j;
        while(i < N && c < n - j) g[r][c++] = a[i++];
        c = n - 1 - j;
        r++;
        while(i < N && r < m - j) g[r++][c] = a[i++];
        r = m - 1 - j;
        c--;
        while(i < N && c >= j) g[r][c--] = a[i++];
        c = j;
        r--;
        while(i < N && r > j) g[r--][c] = a[i++];
    }
    for(r = 0; r < m; r++) {
        printf("%d", g[r][0]);
        for(c = 1; c < n; c++)
            printf(" %d", g[r][c]);
        printf("\n");
    }
    return 0;
}

