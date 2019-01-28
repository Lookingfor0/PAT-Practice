#include <cstdio>


int main()
{
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int res[31] = {0};
    int i = 0;
    do
    {
        res[i++] = sum % d;
        sum = sum / d;
    }
    while(sum);
    while(i--)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}

