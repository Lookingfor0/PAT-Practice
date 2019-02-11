#include <cstdio>


const int maxn = 1000001;  // ��һ�� 0 �͹������ˣ����Ի���ȡ���ã�������Ӱ��ʱ�临�Ӷ�
int prime[maxn], num = 0;
bool p[maxn] = { 0 };

void Find_Prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (!p[i])
		{
			prime[num++] = i;
			if (num >= n) break;  // �ҵ��� n ����������ǰ�˳�
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
