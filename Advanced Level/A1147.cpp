#include <iostream>

using namespace std;

bool isHeap(int bt[], int N, int flag) {
    // flag == 1 表示判断是否是最大堆
    if(flag) {
        for(int i = 2; i <= N; i++)
            if(bt[i] > bt[i / 2]) return false;
    } else {
        for(int i = 2; i <= N; i++)
            if(bt[i] < bt[i / 2]) return false;
    }
    return true;
}

void PostTraversal(int bt[], int N, int pos) {
    if(pos > N) {
        return;
    } else {
        PostTraversal(bt, N, pos * 2);
        PostTraversal(bt, N, pos * 2 + 1);
        if(pos != 1) printf("%d ", bt[pos]);
        else printf("%d\n", bt[1]);
    }
}

int main() {
    int N, M, bt[1001];
    bool minHeap, maxHeap;
    scanf("%d%d", &M, &N);
    while(M--) {
        for(int i = 1; i <= N; i++)
            scanf("%d", &bt[i]);
        minHeap = isHeap(bt, N, 0);
        maxHeap = isHeap(bt, N, 1);
        if(minHeap)
            printf("Min Heap\n");
        else if(maxHeap)
            printf("Max Heap\n");
        else
            printf("Not Heap\n");
        PostTraversal(bt, N, 1);
    }
    return 0;
}

