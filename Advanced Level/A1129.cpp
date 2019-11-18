// 这个就没超时。。。
#include <iostream>
#include <set>

using namespace std;

struct item {
    int q, f;  // query and frequency
    friend bool operator < (const item &a, const item &b) {
        return (a.f != b.f) ? a.f > b.f : a.q < b.q;
    }
};

int main() {
    int N, K, t, fre[50001] = {0};
    set<item> rec;
    scanf("%d%d", &N, &K);
    scanf("%d", &t);
    fre[t]++;
    rec.insert({t, 1});
    while(--N) {
        scanf("%d", &t);
        printf("%d:", t);
        int i = 0;
        for(auto tit = rec.begin(); i < K && tit != rec.end(); tit++, i++)
            printf(" %d", (*tit).q);
        printf("\n");
        auto it = rec.find({t, fre[t]});
        if(it == rec.end()) {
            rec.insert({t, 1});
            fre[t]++;
        }
        else {
            rec.erase(it);
            rec.insert({t, ++fre[t]});
        }
    }
    return 0;
}


// 觉得写得挺好的，但是超时了(沮丧脸)
#include <iostream>
#include <vector>

using namespace std;

struct item {
    int q, f;  // query and frequency
};

int main() {
    int N, K, t, index = 0;
    bool m[50001] = {0};
    struct item rec[50001];
    scanf("%d%d", &N, &K);
    scanf("%d", &t);
    m[t] = true;
    rec[index++] = {t, 1};
    int i = 0, j;
    while(--N) {
        scanf("%d", &t);
        printf("%d:", t);
        for(i = 0; i < K && i < index; i++)
            printf(" %d", rec[i].q);
        printf("\n");
        if(m[t]) {
            for(i = 0; i < index; i++)
                if(rec[i].q == t) break;
            rec[i].f++;
        } else {
            m[t] = true;
            rec[index++] = {t, 1};
            i = index - 1;
        }
        for(j = i - 1; j >= 0; j--)
            if(rec[j].f > rec[i].f || (rec[j].f == rec[i].f && rec[j].q < rec[i].q)) break;
        struct item ti = rec[i];
        j++;
        for(; j < i; i--)
            rec[i] = rec[i - 1];
        rec[j] = ti;
    }
    return 0;
}

