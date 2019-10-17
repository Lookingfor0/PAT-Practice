#include <cstdio>
#include <algorithm>

using namespace std;

void To_array(int n, int num[]) {
    for(int i = 3; i >= 0; i--) {
        num[i] = n % 10;
        n /= 10;
    }
}

int To_number(int num[], bool flag) {
    // flag = 1 表示转换成最大值
    int n = 0;
    if(flag) {
        for(int i = 3; i >= 0; i--)
            n = n * 10 + num[i];
    } else {
        for(int i = 0; i < 4; i++)
            n = n * 10 + num[i];
    }
    return n;
}

int main() {
    int n, num[4], MIN, MAX;
    scanf("%d", &n);
    do {
        To_array(n, num);
        sort(num, num + 4);  // 数字按从小到大排列
        MIN = To_number(num, 0);
        MAX = To_number(num, 1);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);
    } while(n != 0 && n != 6174);  // 这里是为了避免 n = 6174 没有输出
    return 0;
}

