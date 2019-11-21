#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int k;
    string s;
    vector<char> ans, temp;
    scanf("%d", &k);
    cin >> s;
    unordered_map<char ,bool> notBroken, isBroken;
    int cnt;
    for(int i = 0; i < s.size(); i += cnt) {
        char c = s[i];
        cnt = 1;
        for(int j = i + 1; j < s.size() && s[j] == c; j++)
            cnt++;
        if(cnt % k == 0)
            ans.push_back(c);
        else
            notBroken[c] = true;
    }
    for(auto it = ans.begin(); it != ans.end(); it++)
        if(!notBroken[*it] && !isBroken[*it]) {  // isBroken是保证ans里坏键不重复出现
            temp.push_back(*it);
            isBroken[*it] = true;
        }
    ans = temp;
    for(auto it = ans.begin(); it != ans.end(); it++)
        printf("%c", *it);
    printf("\n");
    for(int i = 0; i < s.size(); i++) {
        if(isBroken.find(s[i]) != isBroken.end())
            i += k - 1;
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

