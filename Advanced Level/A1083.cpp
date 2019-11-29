#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string Name, ID;
};

int main() {
    int N, g1, g2, cnt = 0;
    vector<Node> v(101);
    bool f[101] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        struct Node n;
        int g;
        cin >> n.Name >> n.ID >> g;
        f[g] = true;
        v[g] = n;
    }
    scanf("%d%d", &g1, &g2);
    for(int i = g2; i >= g1; i--) {
        if(f[i]) {
            cnt++;
            printf("%s %s\n", v[i].Name.c_str(), v[i].ID.c_str());
        }
    }
    if(cnt == 0) printf("NONE\n");
    return 0;
}

