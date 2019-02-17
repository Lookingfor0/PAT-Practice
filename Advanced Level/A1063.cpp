#include <cstdio>
#include <set>

using namespace std;


int main()
{
	set<int> st[51];
	int N, M, K;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf("%d", &temp);
			st[i].insert(temp);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b, nc = 0;
		scanf("%d%d", &a, &b);
		// ����һ�鿴�Ƿ�����ͬԪ��
		// ����ٴ���һ�� set ���������������е�Ԫ�أ��ᳬʱ
		for (set<int>::iterator j = st[a].begin(); j != st[a].end(); j++)
			if (st[b].find(*j) != st[b].end())
				nc++;
		printf("%.1f%%\n", nc * 100.0 / (st[a].size() + st[b].size() - nc));  // ע�⣺�ٷֺ�Ҫ�� %% 
	}
	return 0;
}
