#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int N, M, S;
vector<int> res;

struct TNode {
    int index, weight;
    vector<int> son;
}Nodes[100];

bool cmp(int A, int B) {
    return Nodes[A].weight > Nodes[B].weight;
}


void Path(int root, int weight) {
    int ww = Nodes[root].weight + weight;
    res.push_back(Nodes[root].weight);
    if(Nodes[root].son.empty() && S == ww) {
        bool start = true;
        for(vector<int>::iterator i = res.begin(); i != res.end(); i++) {
            if(start) {
                start = false;
                printf("%d", *i);
            } else
                printf(" %d", *i);
        }
        printf("\n");
    } else if(ww < S) {
        for(vector<int>::iterator i = Nodes[root].son.begin(); i != Nodes[root].son.end(); i++)
            Path(*i, ww);
    }
    res.pop_back();
}

int main() {
    scanf("%d%d%d", &N, &M, &S);
    int ID, K, id;
    for(int i = 0; i < N; i++) {
        scanf("%d", &Nodes[i].weight);
    }
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &ID, &K);
        for(int j = 0; j < K; j++) {
            scanf("%d", &id);
            Nodes[ID].son.push_back(id);
        }
        sort(Nodes[ID].son.begin(), Nodes[ID].son.end(), cmp);  // 对孩子节点从大到小排序，这样输出的时候就是按题目要求的顺序输出
    }
    Path(0, 0);
    return 0;
}

