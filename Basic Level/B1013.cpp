#include <cstdio>


const int maxn = 1000001;  // 少一个 0 就过不了了，所以还是取大点好，反正不影响时间复杂度
int prime[maxn], num = 0;
bool p[maxn] = { 0 };

void Find_Prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (!p[i])
		{
			prime[num++] = i;
			if (num >= n) break;  // 找到了 n 个素数就提前退出
			for (int j = i + i; j < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	Find_Prime(n);
	for (int i = m - 1; i < n; i++)
	{
		printf("%d", prime[i]);
		count++;
		if (count == 10 || i == n - 1)
		{
			printf("\n");
			count = 0;
		}
		else
		{
			printf(" ");
		}
	}
	return 0;
}
