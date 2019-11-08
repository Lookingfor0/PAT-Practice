// 这题有点难，主要有很多坑，比如会溢出，直接遍历会超时
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int toNum(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'a' + 10;
}

long long Num(string S, long long radix) {
    long long N = 0;
    for(int i = 0; i < S.size(); i++)
        N = N * radix + toNum(S[i]);
    return N;
}

long long BS(string S, long long num) {
    long long low = toNum(*max_element(S.begin(), S.end())) + 1, high, mid, N;
    high = max(low, num);
    while(low <= high) {
        mid = (low + high) / 2;
        N = Num(S, mid);
        if(N < 0 || N > num) high = mid - 1;  // 小于0是防止溢出, 而且这句要放在 N < num 前面
        else if(N < num) low = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    long long N1, radit, res_radix;
    int tag;
    string S1, S2;
    cin >> S1 >> S2 >> tag >> radit;
    res_radix = (tag == 1)?(BS(S2, Num(S1, radit))):(BS(S1, Num(S2, radit)));
    if(res_radix == -1) printf("Impossible\n");
    else printf("%lld\n", res_radix);
    return 0;
}

