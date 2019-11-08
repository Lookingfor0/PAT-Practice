#include <cstdio>

using namespace std;

int main() {
    int N, now = 0, next, sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &next);
        if(next > now)
            sum += 6 * (next - now);
        else
            sum += 4 * (now - next);
        sum += 5;
        now = next;
    }
    printf("%d\n", sum);
    return 0;
}

