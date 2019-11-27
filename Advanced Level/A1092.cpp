#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> s;
    char c;
    int ext = 0, mis = 0;
    while(scanf("%c", &c) && c != '\n')
        s[c]++;
    while(scanf("%c", &c) && c != '\n')
        s[c]--;
    for(auto it : s) {
        if(it.second > 0) ext += it.second;
        else mis += it.second;
    }
    printf("%s %d\n", (mis != 0) ? "No" : "Yes", (mis < 0) ? -mis : ext);
    return 0;
}

