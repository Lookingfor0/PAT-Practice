#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

struct node {
    string card;
    int score;
};

bool cmp(const node &a, const node &b) {
    return (a.score == b.score) ? a.card < b.card : a.score > b.score;
}

bool cmpp(const pair<string, int> &a, const pair<string, int> b) {
    return (a.second == b.second) ? a.first < b.first : a.second > b.second;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<node> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i].card >> v[i].score;
    for(int i = 1; i <= M; i++) {
        int type;
        bool flag = true;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        if(type == 1) {
            vector<node> ans;
            for(int j = 0; j < v.size(); j++)
                if(v[j].card[0] == term[0]) ans.push_back(v[j]);
            if(ans.empty()) flag = false;
            else {
                sort(ans.begin(), ans.end(), cmp);
                for(int j = 0; j < ans.size(); j++)
                    printf("%s %d\n", ans[j].card.c_str(), ans[j].score);
            }
        } else if(type == 2) {
            int Nt = 0, Ns = 0;
            for(int j = 0; j < v.size(); j++) {
                if(v[j].card.substr(1, 3) == term) {
                    Nt++;
                    Ns += v[j].score;
                }
            }
            if(Nt == 0) flag = false;
            else printf("%d %d\n", Nt, Ns);
        } else {
            unordered_map<string, int> mp;
            for(int j = 0; j < v.size(); j++)
                if(v[j].card.substr(4, 6) == term) mp[v[j].card.substr(1, 3)]++;
            if(mp.empty()) flag = false;
            else {
                vector<pair<string, int>> ans;
                for(auto it : mp) ans.push_back(make_pair(it.first, it.second));
                sort(ans.begin(), ans.end(), cmpp);
                for(int j = 0; j < ans.size(); j++)
                    printf("%s %d\n", ans[j].first.c_str(), ans[j].second);
            }
        }
        if(!flag) printf("NA\n");
    }
    return 0;
}

