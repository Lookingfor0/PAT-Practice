#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

struct Node {
    int addr, key, next;
};

int main() {
    int head, n, p;
    vector<Node> v1, v2;
    unordered_map<int, Node> l;
    unordered_map<int, bool> flag;
    scanf("%d%d", &head, &n);
    for(int i = 0; i < n; i++) {
        int cur, key, next;
        scanf("%d%d%d", &cur, &key, &next);
        l[cur] = Node({cur, key, next});
    }
    p = head;
    while(p != -1) {
        auto node = l[p];
        if(!flag[abs(node.key)]) {
            flag[abs(node.key)] = true;
            v1.push_back(node);
        } else
            v2.push_back(node);
        p = node.next;
    }
    for(int i = 0; i + 1 < v1.size(); i++)
        printf("%05d %d %05d\n", v1[i].addr, v1[i].key, v1[i + 1].addr);
    if(v1.size() >= 1) printf("%05d %d -1\n", v1[v1.size() - 1].addr, v1[v1.size() - 1].key);
    for(int i = 0; i + 1 < v2.size(); i++)
        printf("%05d %d %05d\n", v2[i].addr, v2[i].key, v2[i + 1].addr);
    if(v2.size() >= 1) printf("%05d %d -1", v2[v2.size() - 1].addr, v2[v2.size() - 1].key);
    return 0;
}

