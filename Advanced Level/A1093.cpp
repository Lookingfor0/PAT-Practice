// new method
#include <cstdio>

#define MAXN 100000
#define MOD 1000000007
using namespace std;

int main() {
    int p = 0, pa = 0, pat = 0;  // p 表示当前以读取的字符中 p 的个数，pa 表示当前读取的字符中 pa 串的个数，pat 以此类推
    int i = 0;
    char t;
    while(scanf("%c", &t) != EOF) {
        i++;
        switch(t) {
            case 'P': p += 1; break;
            case 'A': pa += p; pa %= MOD; break;
            case 'T': pat += pa; pat %= MOD; break;
        }
    }
    printf("%d\n", pat);
    return 0;
}




// old method

#include <cstdio>
#include <cstring>


const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = { 0 };  // 每个点左边（含）的 P 的数目

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
			leftNumP[i] = leftNumP[i - 1];
		if (str[i] == 'P')
			leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i > 0; i--)
	{
		if (str[i] == 'T')
			rightNumT++;
		else if (str[i] == 'A')
			ans = (ans + rightNumT * leftNumP[i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}

