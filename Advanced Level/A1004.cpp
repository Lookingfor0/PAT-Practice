#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v[110];  // 存放树结构
int num[100] = { 0 };
int max_level = 0;

void dfs(int root, int level) {
	if (v[root].empty()) {
		num[level]++;
		max_level = max(level, max_level);
		return;
	}
	for (int i = 0; i < v[root].size(); i++) {
		dfs(v[root][i], level + 1);
	}
	return;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (N == 0) return 0;
	// 构建树
	for (int i = 0; i < M; i++) {
		int node, k, c;
		scanf("%d %d", &node, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &c);
			v[node].push_back(c);
		}
	}
	dfs(1, 0);
	printf("%d", num[0]);
	for (int i = 1; i <= max_level; i++) {
		printf(" %d", num[i]);
	}
	return 0;
}