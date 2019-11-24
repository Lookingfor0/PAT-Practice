#include <iostream>

using namespace std;

int main() {
    int N;
    double sum = 0.0, t;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%lf", &t);
//        sum += i * (N - i + 1) * t;  // 这样写最后两个测试点通不过
        sum += t * i * (N - i + 1);  // 这样写就过了。。。
    }
    printf("%.2f", sum);
    return 0;
}

