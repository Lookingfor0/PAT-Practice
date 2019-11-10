#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M, K, Q, dur[1001], finish[1001], cus = 1, inq;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    int maxinq = N * M;
    for(int i = 1; i <= K; i++) {
        scanf("%d", &dur[i]);
        finish[i] = -1;
    }
    queue<int> q[20];
    bool served[1001] = {0};
    inq = 0;
    for(int t = 0; t <= 540; t++) {
        // 黄线内的人
        for(int i = 0; i < N; i++) {
            if(!q[i].empty()) {
                int c = q[i].front();
                served[c] = true;  // 标记，说明已开始处理
                if(--dur[c] == 0) {
					q[i].pop();
					inq--;
					finish[c] = t;
				}
            }
        }
        // 黄线外的人入队
        while(cus <= K && inq < maxinq) {
            int minq = 0;
            for(int i = 1; i < N; i++) {
                if(q[i].size() < q[minq].size())
                    minq = i;
            }
            while(cus <= K && dur[cus] == 0) {finish[cus++] = t;}
            q[minq].push(cus++);
            inq++;
        }
        if(inq == 0) break;
    }
    // 现在处理17：00已经再窗口的人
	for(int i = 0; i < N; i++ ) {
		if(!q[i].empty()) {
			int c = q[i].front();
			if(served[c])  // 这里不确定是否是再17：00入队，题目要求要再17：00之前开始处理才不会被sorry
                finish[c] = dur[c] + 540;
		}
	}
    for(int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if(finish[q] == -1) printf("Sorry\n");
        else {
            int hh = finish[q] / 60 + 8;
            int mm = finish[q] % 60;
            printf("%02d:%02d\n", hh, mm);
        }
    }
    return 0;
}

