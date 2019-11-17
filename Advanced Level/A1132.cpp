// 要注意 a、b 不为 0 时才可以取模，不然会浮点错误
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string Z, A, B;
    scanf("%d", &N);
    while(N--) {
        cin >> Z;
        int K = Z.size();
        A = Z.substr(0, K / 2);
        B = Z.substr(K / 2);
        int z = stoi(Z), a = stoi(A), b = stoi(B);
        if(a != 0 && b != 0 && z % (a * b) == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

