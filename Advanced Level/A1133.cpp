#include <iostream>
#include <vector>

using namespace std;

struct LNode {
    int addr, data, next;
}Nodes[100000];

int main() {
    int head, n, k;
    vector<int> ans;
    scanf("%d%d%d", &head, &n, &k);
    if(head == -1 || n == 0) return 0;
    for(int i = 0; i < n; i++) {
        int addr, data, next;
        scanf("%d%d%d", &addr, &data, &next);
        Nodes[addr] = {addr, data, next};
    }
    for(int i = head; i != -1; i = Nodes[i].next)
        if(Nodes[i].data < 0) ans.push_back(i);
    for(int i = head; i != -1; i = Nodes[i].next)
        if(Nodes[i].data >= 0 && Nodes[i].data <= k) ans.push_back(i);
    for(int i = head; i != -1; i = Nodes[i].next)
        if(Nodes[i].data > k) ans.push_back(i);
    for(int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i], Nodes[ans[i]].data, ans[i + 1]);
    printf("%05d %d -1\n", ans[ans.size() - 1], Nodes[ans[ans.size() - 1]].data);  // 注意可能有节点不在链表上，所以不能用 n 代替ans.size()
    return 0;
}

// 一开始的方法
// 第二个测试点超时，不知道为什么
#include <iostream>

using namespace std;

struct LNode {
    int data, next;
}Nodes[100001];

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);
    if(head == -1) return 0;
    Nodes[100000].next = head;  // 加个头节点
    for(int i = 0; i < n; i++) {
        int addr;
        scanf("%d", &addr);
        scanf("%d%d", &Nodes[addr].data, &Nodes[addr].next);
    }
    int pre, pos = 100000, cur = head;
    pre = pos;
    while(cur != -1) {
        if(Nodes[cur].data < 0) {
            int next = Nodes[cur].next;
            Nodes[pre].next = next;
            Nodes[cur].next = Nodes[pos].next;
            Nodes[pos].next = cur;
            pos = cur;
            cur = next;
        } else {
            pre = cur;
            cur = Nodes[cur].next;
        }
    }
    pre = pos;
    cur = Nodes[pre].next;
    while(cur != -1) {
        if(Nodes[cur].data <= k) {
            int next = Nodes[cur].next;
            Nodes[pre].next = next;
            Nodes[cur].next = Nodes[pos].next;
            Nodes[pos].next = cur;
            pos = cur;
            cur = next;
        } else {
            pre = cur;
            cur = Nodes[cur].next;
        }
    }
    cur = head = Nodes[100000].next;
    // 这里至少有一个节点
    while(Nodes[cur].next != -1) {
        printf("%05d %d %05d\n", cur, Nodes[cur].data, Nodes[cur].next);
        cur = Nodes[cur].next;
    }
    printf("%05d %d -1\n", cur, Nodes[cur].data);
    return 0;
}

