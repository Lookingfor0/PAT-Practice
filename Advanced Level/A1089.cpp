#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, a[100], b[100], index = 1, p;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    for(int i = 0; i < N; i++) scanf("%d", &b[i]);
    while(index < N && b[index - 1] <= b[index]) index++;  // 一定要加等号
    p = index;
    while(p < N && a[p] == b[p]) p++;
    if(p == N) {
        printf("Insertion Sort\n");
        sort(a, a + index + 1);
    } else {
        printf("Merge Sort\n");
        bool flag = true;
        int k = 1;
        while(flag) {
            flag = false;
            int i;
            for(i = 0; i < N; i++)
                if(a[i] != b[i]) { flag = true; break; }
            k *= 2;
            for(i = 0; i < N / k; i++)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + i * k, a + N);
        }
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}

