#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>  // ע���� cstring ���� string
using namespace std;

vector<int> cls[2510];  // ���ÿ���ε���
char names[40010][5];  // ���ÿ���˵�����

bool cmp(int a, int b)
{
	return strcmp(names[a], names[b]) <= 0;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		int n;
		char name[5];
		scanf("%s %d", names[i], &n);
		for (int j = 0; j < n; j++)
		{
			int cid;
			scanf("%d", &cid);
			cls[cid].push_back(i);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		printf("%d %d\n", i, cls[i].size());
		sort(cls[i].begin(), cls[i].end(), cmp);
		for (int j = 0; j < cls[i].size(); j++)
		{
			printf("%s\n", names[cls[i][j]]);
		}
	}
	return 0;
}
