#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct School {
    string name;
    int Ns;
    double TWS;  // 这里是对综合取整数部分，不然通不过最后一个测试点
    School(string _name, int _TWS) {
        name = _name;
        TWS = _TWS;
        Ns = 1;
    }
    School() {}
};

bool cmp(School a, School b) {
    if((int)a.TWS == (int)b.TWS) {
        if(a.Ns == b.Ns)
            return a.name < b.name;
        else
            return a.Ns < b.Ns;
    } else
        return (int)a.TWS > (int)b.TWS;
}

int main() {
    int N, score, index;
    string id, sch;
    unordered_map<string, int> m;
    scanf("%d", &N);
    vector<School> v;  // 下标从1开始
    v.push_back(School());  // 占个位
    index = 1;
    while(N--) {
        cin >> id >> score >> sch;
        for(int i = 0; i < sch.length(); i++) {
            if(sch[i] >= 'A' && sch[i] <= 'Z')
                sch[i] += 'a' - 'A';
        }
        int i = m[sch];
        double ws = id[0] == 'B' ? (score / 1.5) : id[0] == 'A' ? score : (score * 1.5);
        if(i) {
            v[i].Ns++;
            v[i].TWS += ws;
        } else {
            m[sch] = index++;
            v.push_back(School(sch, ws));
        }
    }
    sort(v.begin() + 1, v.end(), cmp);
    int r;
    printf("%d\n", v.size() - 1);
    for(int i = 1; i < v.size(); i++) {
        if(i == 1 || (int)v[i].TWS != (int)v[i - 1].TWS) {
            printf("%d %s %d %d\n", i, v[i].name.c_str(), (int)v[i].TWS, v[i].Ns);
            r = i;
        } else
            printf("%d %s %d %d\n", r, v[i].name.c_str(), (int)v[i].TWS, v[i].Ns);
    }
    return 0;
}

