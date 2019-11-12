#include <iostream>
#include <vector>

using namespace std;

int N, Heap[1001];
vector<int> v;

void DFS(int root) {
    v.push_back(root);
    if(root * 2 > N) {
        printf("%d", Heap[v[0]]);
        for(int i = 1; i < v.size(); i++)
            printf(" %d", Heap[v[i]]);
        printf("\n");
    } else {
        int l = root * 2, r = root * 2 + 1;
        if(r <= N) {
            DFS(r);
        }
        DFS(l);
    }
    v.pop_back();
}

bool isHeap(int root, int flag) {  // 更简单的办法是遍历, 从第二个节点开始遍历，如果比父节点小，就不是小顶堆，如果比父节点大，就不是大顶堆
    if(root > N) return true;
    bool t = isHeap(root * 2, flag) && isHeap(root * 2 + 1, flag);
    if(root == 1)
        return t;
    else if(flag == 1)
        return t && Heap[root] <= Heap[root / 2];
    else
        return t && Heap[root] >= Heap[root / 2];
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &Heap[i]);
    DFS(1);
    if(isHeap(1, 1))
        printf("Max Heap\n");
    else if(isHeap(1, 0))
        printf("Min Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}

