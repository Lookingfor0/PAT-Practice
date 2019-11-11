#include <iostream>
#include <string>

using namespace std;

bool isPrime(int N) {
    if(N == 0 || N == 1) return false;
    for(int i = 2; i * i <= N; i++)
        if(N % i == 0) return false;
    return true;
}

int main() {
    int L, K;
    string s;
    cin >> L >> K >> s;
    for(int i = 0; i <= L - K; i++) {
        string t = s.substr(i, K);
        int num = stoi(t);
        if(isPrime(num)) {
            cout << t << endl;
            return 0;
        }
    }
    printf("404\n");
    return 0;
}

