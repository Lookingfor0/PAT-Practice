// SPFA version
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 500;
const int INF = 0x3fffffff;

struct Node {
    int v, dis;
    Node (int _v, int _dis) : v(_v), dis(_dis) {}  // 构造函数
};

vector<Node> Adj[MAXN];  // 邻接表

int n, m, st, ed, weight[MAXN];
int d[MAXN], w[MAXN], num[MAXN];
set<int> pre[MAXN];

void SPFA(int s) {
    fill(d, d + n, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    bool inq[MAXN] = {0};
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i].v;
            int dis = Adj[u][i].dis;
            if(d[v] > dis + d[u]) {
                d[v] = dis + d[u];
                w[v] = weight[v] + w[u];
                pre[v].clear();
                pre[v].insert(u);
                num[v] = num[u];
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            } else if(d[v] == dis + d[u]) {
                if(w[v] < weight[v] + w[u]) w[v] = weight[v] + w[u];
                // 这里也要把 v 入队，不然会出错（可能会导致num计算不正确？）
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
                pre[v].insert(u);
                num[v] = 0;  // 重新统计 num
                set<int>::iterator it;
                for(it = pre[v].begin(); it != pre[v].end(); it++)
                    num[v] += num[*it];
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    int u, v, wt;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &wt);
        Adj[u].push_back(Node(v, wt));
        Adj[v].push_back(Node(u, wt));
    }
    SPFA(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}


// Bellman version
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 500;
const int INF = 0x3fffffff;

struct Node {
    int v, dis;
    Node (int _v, int _dis) : v(_v), dis(_dis) {}  // 构造函数
};

vector<Node> Adj[MAXN];  // 邻接表

int n, m, st, ed, weight[MAXN];
int d[MAXN], w[MAXN], num[MAXN];
set<int> pre[MAXN];

void Bellman(int s) {
    fill(d, d + n, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n - 1; i++) {
        for(int u = 0; u < n; u++) {
            for(int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[v] > dis + d[u]) {
                    d[v] = dis + d[u];
                    w[v] = weight[v] + w[u];
                    pre[v].clear();
                    pre[v].insert(u);
                    num[v] = num[u];
                } else if(d[v] == dis + d[u]) {
                    if(w[v] < weight[v] + w[u]) w[v] = weight[v] + w[u];
                    pre[v].insert(u);
                    num[v] = 0;  // 重新统计 num
                    set<int>::iterator it;
                    for(it = pre[v].begin(); it != pre[v].end(); it++)
                        num[v] += num[*it];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    int u, v, wt;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &wt);
        Adj[u].push_back(Node(v, wt));
        Adj[v].push_back(Node(u, wt));
    }
    Bellman(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500;
const int INF = 0x3fffffff;

int Teams[MAXN], Roads[MAXN][MAXN], dis[MAXN], mTeam[MAXN], paths[MAXN];
bool vis[MAXN] = {0};

void Dijkstra(int N, int s) {
    fill(dis, dis + N, INF);
    fill(mTeam, mTeam + N, 0);
    fill(paths, paths + N, 0);
    dis[s] = 0;
    mTeam[s] = Teams[s];
    paths[s] = 1;
    int u, v, mindis;
    for(int i = 0; i < N; i++) {
        u = -1;
        mindis = INF;
        for(int j = 0; j < N; j++) {
            if(!vis[j] && dis[j] < mindis) {
                mindis = dis[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(v = 0; v < N; v++) {
            if(!vis[v] && Roads[u][v] != INF) {
                if(dis[v] == dis[u] + Roads[u][v]) {
                    paths[v] += paths[u];
                    if(mTeam[v] < mTeam[u] + Teams[v]) mTeam[v] = mTeam[u] + Teams[v];
                } else if(dis[v] > dis[u] + Roads[u][v]) {
                    dis[v] = dis[u] + Roads[u][v];
                    paths[v] = paths[u];
                    mTeam[v] = mTeam[u] + Teams[v];
                }
            }
        }
    }
}

int main() {
    int N, M, ST, DIR, c1, c2, l;
    scanf("%d%d%d%d", &N, &M, &ST, &DIR);
    for(int i = 0; i < N; i++)
        scanf("%d", &Teams[i]);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Roads[i][j] = Roads[j][i] = INF;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        Roads[c1][c2] = Roads[c2][c1] = l;
    }
    Dijkstra(N, ST);
    printf("%d %d\n", paths[DIR], mTeam[DIR]);
    return 0;
}



// old version
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
	fill(path[0], path[0] + 501 * 501, MAX_DIS);  // ע???????ĵ?ַ???﷽ʽ
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
		// Ѱ?ҵ?ǰ??????????????һ??ʱ???̾????ĵ??????Ż?
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
