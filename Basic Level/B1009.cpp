#include <cstdio>


int main()
{
    int num = 0;
    char words[80][80];
    while(scanf("%s", words[num]) != EOF)
    {
        num++;
    }
    for(int i = num - 1; i >= 0; i--)
    {
        printf("%s", words[i]);
        if(i != 0)
            printf(" ");
    }
    return 0;
}
