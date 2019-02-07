#include <cstdio>
#include <cstring>


const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = { 0 };  // 每个点左边（含）的 P 的数目

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
			leftNumP[i] = leftNumP[i - 1];
		if (str[i] == 'P')
			leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i > 0; i--)
	{
		if (str[i] == 'T')
			rightNumT++;
		else if (str[i] == 'A')
			ans = (ans + rightNumT * leftNumP[i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}

