#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> pre, in, post;
stack<int> s;

void GetPost(int ps, int is, int ie) {
    if(is > ie) return;
    int root = pre[ps], i = is;
    while(i <= ie && in[i] != root) i++;
    GetPost(ps + 1, is, i - 1);
    GetPost(ps + i - is + 1, i + 1, ie);
    post.push_back(pre[ps]);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < 2 * N; i++) {
        string op;
        int n;
        cin >> op;
        if(op[1] == 'u') {
            cin >> n;
            s.push(n);
            pre.push_back(n);
        } else {
            n = s.top();
            s.pop();
            in.push_back(n);
        }
    }
    GetPost(0, 0, N - 1);
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}

