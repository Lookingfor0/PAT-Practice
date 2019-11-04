#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, In[30], Post[30];

struct Node {
    int index, data;
};

vector<Node> T;

void Traversal(int start, int end, int root, int index) {
    if(start > end) return;
    int i = start;
    while(i < end && In[i] != Post[root])
        i++;
    T.push_back({index, Post[root]});
    Traversal(start, i - 1, root + i - end - 1, index * 2);
    Traversal(i + 1, end, root - 1, index * 2 + 1);
}

bool cmp(Node A, Node B) {
    return A.index < B.index;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &Post[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &In[i]);
    Traversal(0, N - 1, N - 1, 1);
    sort(T.begin(), T.end(), cmp);
    printf("%d", T[0].data);
    for(int i = 1; i < N; i++)
        printf(" %d", T[i].data);
    printf("\n");
    return 0;
}

