#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p = 2, a[101], b[101];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    while(p <= n && b[p - 1] <= b[p]) p++;  // 这里一定要加等号。。。。坑了我好久
    int index = p;
    while(p <= n && a[p] == b[p]) p++;
    if(p == n + 1) {
        printf("Insertion Sort\n");
        sort(b + 1, b + index + 1);
    } else {
        printf("Heap Sort\n");
        index = n;
        while(index > 1 && b[index] >= b[1]) index--;
        swap(b[1], b[index]);
        int x = b[1], p, c;
        for(p = 1; p * 2 < index; p = c) {
            c = p * 2;
            if(c + 1 < index && b[c + 1] > b[c]) c++;
            if(b[c] > x) b[p] = b[c];
            else break;
        }
        b[p] = x;
    }
    printf("%d", b[1]);
    for(int i = 2; i <= n; i++)
        printf(" %d", b[i]);
    return 0;
}

