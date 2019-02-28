#include <cstdio>
#include <algorithm>
using namespace std;


const int MAX_DIS = 99999999;

int main() {
	int N, M, C1, C2;
	int num[501]; // number of rescue team of each city
	int path[501][501];  // distance of each path
	int dis[501]; // minimal distance between each city and C1
	int total_num[501] = { 0 };  // total number of rescue team of all the rescue path from C1 
	int diff_path[501] = { 0 };  // different path from C1 to each city
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++) {
		scanf("%d", num + i);
	}
	fill(path[0], path[0] + 501 * 501, MAX_DIS);  // 注意这里的地址表达方式
	for (int i = 0; i < M; i++) {
		int a, b, dis;
		scanf("%d %d %d", &a, &b, &dis);
		path[a][b] = path[b][a] = dis;
	}
	fill(dis, dis + 501, MAX_DIS);
	bool is_min[501] = { false };
	dis[C1] = 0;
	total_num[C1] = num[C1];
	diff_path[C1] = 1;
	for (int i = 0; i < N; i++) {
		int cur = -1, min_dis = MAX_DIS;
		// 寻找当前离起点最近但不一定时最短距离的点进行优化
		for (int j = 0; j < N; j++) {
			if (!is_min[j] && dis[j] < min_dis) {
				min_dis = dis[j];
				cur = j;
			}
		}
		if (cur == -1) break;
		is_min[cur] = true;
		for (int j = 0; j < N; j++) {
			if (is_min[j]) continue;
			if (path[cur][j] + dis[cur] < dis[j]) {
				dis[j] = path[cur][j] + dis[cur];
				total_num[j] = num[j] + total_num[cur];
				diff_path[j] = diff_path[cur];
			} else if (path[cur][j] + dis[cur] == dis[j]) {
				diff_path[j] += diff_path[cur];
				if (total_num[j] < num[j] + total_num[cur]) {
					total_num[j] = num[j] + total_num[cur];
				}
			}
		}
	}
	printf("%d %d\n", diff_path[C2], total_num[C2]);
	return 0;
}