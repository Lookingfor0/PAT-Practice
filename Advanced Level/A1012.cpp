#include <cstdio>
#include <algorithm>

using namespace std;

struct SNode {
    int id, best;
    int score[4], rank[4];
}Stu[2001];

int flag;

bool cmp1(SNode a, SNode b) {
    return a.score[flag] > b.score[flag];
}

int main() {
    int N, M;
    char sub[4] = { 'A', 'C', 'M', 'E' };
    bool exist[1000000] = {0};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &Stu[i].id, &Stu[i].score[1], &Stu[i].score[2], &Stu[i].score[3]);
        Stu[i].score[0] = (Stu[i].score[1] + Stu[i].score[2] + Stu[i].score[3]) / 3;
        exist[Stu[i].id] = true;
        Stu[i].best = 0;
    }
    for(flag = 0; flag < 4; flag++) {
        sort(Stu, Stu + N, cmp1);
        Stu[0].rank[flag] = 1;
        if(Stu[0].rank[Stu[0].best] > 1) Stu[0].best = flag;
        for(int i = 1; i < N; i++) {
            if(Stu[i].score[flag] != Stu[i - 1].score[flag]) Stu[i].rank[flag] = i + 1;
            else Stu[i].rank[flag] = Stu[i - 1].rank[flag];
            if(Stu[i].rank[Stu[i].best] > Stu[i].rank[flag]) Stu[i].best = flag;
        }
    }
    for(int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        if(exist[id]) {
            for(int j = 0; j < N; j++) {
                if(Stu[j].id == id) {
                    printf("%d %c\n", Stu[j].rank[Stu[j].best], sub[Stu[j].best]);
                    break;
                }
            }
        } else
            printf("N/A\n");
    }
    return 0;
}
