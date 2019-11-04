#include <stdio.h>
#include <algorithm>

using namespace std;

// 注意可能存在无效的节点以及有效节点数为 0 的情况
// Tips：sort 函数必须为一个强比较

const int maxn = 100000;

struct LNode {
    int Addr, Key, Next;
    bool flag;
}List[maxn];

bool cmp(struct LNode &A, struct LNode &B) {
    if(!A.flag || !B.flag)
        return A.flag > B.flag;
    else
        return A.Key < B.Key;
}

int main() {
    int N, Head, addr;
    scanf("%d%d", &N, &Head);
    for(int i = 0; i < N; i++) {
        scanf("%d", &addr);
        scanf("%d%d", &List[addr].Key, &List[addr].Next);
        List[addr].Addr = addr;
    }
    addr = Head;
    int c = 0;
    while(addr != -1) {
        List[addr].flag = true;
        addr = List[addr].Next;
        c++;
    }
    if(c == 0) printf("0 -1\n");
    else {
        sort(List, List + maxn, cmp);
        printf("%d %05d\n", c, List[0].Addr);
        for(int i = 0; i < c - 1; i++)
            printf("%05d %d %05d\n", List[i].Addr, List[i].Key, List[i + 1].Addr);
        printf("%05d %d -1\n", List[c - 1].Addr, List[c - 1].Key);
    }
    return 0;
}

