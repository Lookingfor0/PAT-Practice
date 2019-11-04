#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Bang {
    int Head, Member;
};

const int maxnum = 26 * 26 * 26;
map<int, string> Name;  // 记录 ID 与名字的对应关系
int Edges[maxnum][maxnum] = { 0 };
int Weight[maxnum] = { 0 };
bool visited[maxnum] = { 0 };
vector<Bang> Bangs;

int StrToInt(string S) {
    int res = 0;
    for(int i = 0; i < S.length(); i++)
        res = res * 10 + S[i] - 'A';
    return res;
}

int m, head, tw;
void DFS(int v) {
    visited[v] = true;
    m++;
    if(Weight[v] > Weight[head])
        head = v;
    for(int i = 0; i < maxnum; i++) {
        if(Edges[v][i]) {
            tw += Edges[v][i] + Edges[i][v];
            Edges[i][v] = Edges[v][i] = 0;  // 防止有环
            if(!visited[i])
                DFS(i);
        }
    }
}

bool cmp(Bang A, Bang B) {
    return A.Head < B.Head;
}

int main() {
    int N, K, n1, n2, t;
    string s1, s2;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2 >> t;
        n1 = StrToInt(s1);
        n2 = StrToInt(s2);
        if(!Name.count(n1)) Name[n1] = s1;
        if(!Name.count(n2)) Name[n2] = s2;
        Edges[n1][n2] = t;
        Weight[n1] += t;
        Weight[n2] += t;
    }
    int b = 0;
    for(int i = 0; i < maxnum; i++) {
        if(Name.count(i) && !visited[i]) {
            m = 0;
            head = i;
            tw = 0;
            DFS(i);
            if(tw > K && m > 2) {
                Bangs.push_back({head, m});
                b++;
            }
        }
    }
    sort(Bangs.begin(), Bangs.end(), cmp);
    cout << b << endl;
    for(auto i = Bangs.begin(); i != Bangs.end(); i++)
        cout << Name[(*i).Head] << " " << (*i).Member << endl;
    return 0;
}

