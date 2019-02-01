#include <cstdio>


int main()
{
    int nums[10];
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", nums + i);
    }
    // 先找一个最小的非 0 数，放到最前
    // 这里由于只需要输出，所以我们可以一个一个数字地输出，并不需要求出那个数。
    for(int i = 1; i < 10; i++)
    {
        if(nums[i])
        {
            nums[i]--;
            printf("%d", i);
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        while(nums[i]--)
            printf("%d", i);
    }
    printf("\n");
    return 0;
}

