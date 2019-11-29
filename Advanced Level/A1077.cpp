#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string ans, t;
    scanf("%d", &N);
    getchar();
    getline(cin, ans);
    for(int i = 1; i < N; i++) {
        getline(cin, t);
        int j;
        for(j = 0; j < ans.size(); j++)
            if(ans[ans.size() - 1 - j] != t[t.size() - 1 - j]) break;
        ans = ans.substr(ans.size() - j, j);
    }
    if(ans.size()) cout << ans;
    else cout << "nai";
    return 0;
}

