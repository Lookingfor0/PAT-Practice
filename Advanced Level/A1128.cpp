#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int K, N, row[1001];
    bool rnum[1001], flag;
    scanf("%d", &K);
    while(K--) {
        memset(rnum, 0, sizeof(rnum));
        flag = true;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &row[i]);
            if(rnum[row[i]]) flag =false;
            rnum[row[i]] = true;
        }
        for(int i = 1; i <= N && flag; i++) {
            // 从右上开始, 逆时针验证
            int c, r;
            for(c = i + 1, r = row[i] - 1; flag && c <= N && r >= 1; c++, r--)
                if(row[c] == r) flag = false;
            for(c = i - 1, r = row[i] - 1; flag && c >= 1 && r >= 1; c--, r--)
                if(row[c] == r) flag = false;
            for(c = i - 1, r = row[i] + 1; flag && c >= 1 && r <= N; c--, r++)
                if(row[c] == r) flag = false;
            for(c = i + 1, r = row[i] + 1; flag && c <= N && r <= N; c++, r++)
                if(row[c] == r) flag = false;
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

