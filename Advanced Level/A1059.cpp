#include <cstdio>
#include <cmath>


const int maxn = 100000;
int prime[maxn / 2], pNum = 0;
bool p[maxn] = { 0 };

void Find_Prime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (!p[i])
		{
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j += i)
				p[j] = true;
		}
	}
}

struct PrimeFactor
{
	int prime;
	int num;
} fac[10];

int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1)
		printf("1=1");
	else
	{
		// �����������
		Find_Prime();
		printf("%d=", n);
		int num = 0;
		// n ������ 1 ���䱾��֮������ӣ���һ������ sqrt��n�����ҳɶԳ���
		// ��ö�� sqrt��n�����ڵ����� p���ж����е�������
		// ��� p ���������ӣ��� n ����ֻ��һ������ sqrt��n���������ӣ��п����� n ����
		for (int i = 0; i < pNum && prime[i] <= sqrt(n); i++)
		{
			if (n % prime[i] == 0)
			{
				fac[num].prime = prime[i];
				fac[num].num = 0;
				while (n % prime[i] == 0)
				{
					fac[num].num++;
					n /= fac[num].prime;
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1)
		{
			fac[num].prime = n;
			fac[num++].num = 1;
		}
		for (int i = 0; i < num; i++)
		{
			if (i > 0)
				printf("*");
			printf("%d", fac[i].prime);
			if (fac[i].num > 1)
				printf("^%d", fac[i].num);
		}
	}
	return 0;
}
