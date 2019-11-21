#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, s1 = 0, s2 = 0, num[100000];
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    sort(num, num + N);
    for(int i = 0; i < N / 2; i++) s1 += num[i];
    for(int i = N / 2; i < N; i++) s2 += num[i];
    if(N % 2 == 0) printf("0 ");
    else printf("1 ");
    printf("%d\n", s2 - s1);
    return 0;
}

