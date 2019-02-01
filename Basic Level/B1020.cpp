#include <cstdio>
#include <algorithm>


struct mooncake
{
    double total;
    double storage;
    double price;
};


bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}


int main()
{
    mooncake m[1000];
    int N;
    double D;
    scanf("%d%lf", &N, &D);
    for(int i = 0; i < N; i++)
        scanf("%lf", &m[i].storage);
    for(int i = 0; i < N; i++)
        scanf("%lf", &m[i].total);
    for(int i = 0; i < N; i++)
        m[i].price = m[i].total / m[i].storage;
    std::sort(m, m + N, cmp);
    // 开始卖月饼
    double profit = 0.0;
    double d = 0;
    for(int i = 0; i < N; i++)
    {
        if(d + m[i].storage >= D)
        {
            int s = D - d;
            profit += s * m[i].price;
            break;
        }
        profit += m[i].total;
        d += m[i].storage;
    }
    printf("%.2f\n", profit);
    return 0;
}

