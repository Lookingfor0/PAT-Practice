#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    string name;
    int height;
}a[10000];

bool cmp(Node A, Node B) {
    if(A.height == B.height) return A.name > B.name;
    else return A.height < B.height;
}

int main() {
    int N, K, i, m, last;
    scanf("%d%d", &N, &K);
    for(i = 0; i < N; i++)
        cin >> a[i].name >> a[i].height;
    sort(a, a + N, cmp);
    m = N / K;
    last = N + m - K * m;
    i = N - 1;
    for(int j = 0; j < K; j++) {
        int mid, k = 1, mm;
        if(last > 0) {
            mm = last;
            last = -1;
        } else
            mm = m;
        vector<Node> row(mm);
        mid = mm / 2;
        row[mid] = a[i--];
        while(mid - k >= 0 || k + mid < mm) {
            if(mid - k >= 0) row[mid - k] = a[i--];
            if(mid + k < mm) row[mid + k] = a[i--];
            k++;
        }
        for(int ri = 0; ri + 1 < row.size(); ri++)
            printf("%s ", row[ri].name.c_str());
        printf("%s\n", row[row.size() - 1].name.c_str());
    }
    return 0;
}

