// better version
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main() {
    int N, v[101];
    bool wolf[101], vis[101];
    vector<vector<int>> ans;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &v[i]);
    for(int i = 1; i <= N - 1; i++) {
        for(int j = i + 1; j <= N; j++) {
            memset(wolf, 0, sizeof(wolf));
            memset(vis, 0, sizeof(vis));
            bool flag = true;
            vector<int> ve;
            for(int k = 1; k <= N && flag; k++) {
                int st = v[k];
                if(k == i || k == j) st = -st;
                if(st < 0) {
                    if(vis[-st] && wolf[-st] == false) {
                        flag = false;
                        break;
                    }
                    wolf[-st] = true;
                    if(!vis[-st]) ve.push_back(-st);
                    vis[-st] = true;
                } else {
                    if(vis[st] && wolf[st] == true) {
                        flag = false;
                        break;
                    }
                    vis[st] = true;
                    wolf[st] = false;
                }
            }
            if(flag) {
                int k = 1;
                while(ve.size() < 2 && k <= N) {
                    if(!vis[k])
                        ve.push_back(k);
                    k++;
                }
                if(ve.size() == 2) {  // 注意题目条件
                    if(ve[0] > ve[1])
                        swap(ve[0], ve[1]);
                    if((ve[0] == i && ve[1] != j) || (ve[0] != i && ve[1] == j))
                        ans.push_back(ve);
                }
            }
        }
    }
    if(ans.empty()) {
        printf("No Solution\n");
    } else {
        sort(ans.begin(), ans.end(), cmp);
        printf("%d %d\n", ans[0][0], ans[0][1]);
    }
    return 0;
}

