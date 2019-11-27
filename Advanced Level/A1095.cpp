#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

struct Node {
    char plate[8];
    int time;
    bool flag;
};

bool cmp1(Node A, Node B) {
    if(strcmp(A.plate, B.plate) == 0) return A.time < B.time;
    else return strcmp(A.plate, B.plate) < 0;
}

bool cmp2(Node A, Node B) {
    return A.time < B.time;
}

int main() {
    int N, K, longt = 0;
    scanf("%d%d", &N, &K);
    vector<Node> record(N), car;
    map<string, int> pt;  // 用map这里可以直接按字母顺序输出，不用再排序
    for(int i = 0; i < N; i++) {
        char status[4];
        int h, m, s;
        scanf("%s %d:%d:%d %s", record[i].plate, &h, &m, &s, status);
        record[i].time = h * 3600 + m * 60 + s;
        record[i].flag = (status[0] == 'i') ? true : false;
    }
    sort(record.begin(), record.end(), cmp1);
    for(int i = 0; i < N - 1; i++) {
        if(strcmp(record[i].plate, record[i + 1].plate) == 0 && record[i].flag && !record[i + 1].flag) {
            car.push_back(record[i]);
            car.push_back(record[i + 1]);
            pt[record[i].plate] += record[i + 1].time - record[i].time;
            if(pt[record[i].plate] > longt)
                longt = pt[record[i].plate];
            i++;
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(car.size());
    for(int i = 0; i < car.size(); i++) {
        if(i == 0) cnt[i] = 1;
        else if(car[i].flag)
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = cnt[i - 1] - 1;
    }
    int j = 0;
    for(int i = 0; i < K; i++) {
        int h, m, s, time;
        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 3600 + m * 60 + s;
        while(j < car.size() && time >= car[j].time) j++;
        if(j == 0) printf("0\n");
        else printf("%d\n", cnt[--j]);
    }
    for(auto it : pt)
        if(it.second == longt) printf("%s ", it.first.c_str());
    printf("%02d:%02d:%02d\n", longt / 3600, (longt % 3600) / 60, longt % 60);
    return 0;
}

