#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Student {
    string id;
    int p, mid, fin, grade;
    Student () {p = -1; mid = -1; fin = -1; grade = 0;}
};

bool cmp(Student a, Student b) {
    if(a.grade == b.grade)
        return a.id < b.id;
    else
        return a.grade > b.grade;
}

int main() {
    int P, M, N, score;
    string id;
    vector<Student> ans;
    unordered_map<string, Student> m;
    scanf("%d%d%d", &P, &M, &N);
    for(int i = 0; i < P; i++) {
        cin >> id >> score;
        m[id].p = score;
    }
    for(int i = 0; i < M; i++) {
        cin >> id >> score;
        m[id].mid = score;
    }
    for(int i = 0; i < N; i++) {
        cin >> id >> score;
        m[id].fin = score;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        auto s = it->second;
        if(s.p < 200) continue;
        if(s.mid > s.fin)
            s.grade = s.mid * 0.4 + s.fin * 0.6 + 0.5;
        else
            s.grade = s.fin;
        if(s.grade < 60) continue;
        s.id = it->first;
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].p, ans[i].mid, ans[i].fin, ans[i].grade);
    }
    return 0;
}

