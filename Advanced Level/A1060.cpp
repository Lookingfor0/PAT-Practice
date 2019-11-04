#include <iostream>
#include <string>

using namespace std;

int Standardize(string &A, int N) {
    int e = 0;
    string::iterator it = A.begin();
    while(*it == '0') {
        A.erase(it);
    }
    while(it != A.end() && *it != '.') {
        it++;
        e++;
    }
    if(it != A.end())
        A.erase(it);
    if(e == 0) {
        while(it != A.end() && *it == '0') {
            e--;
            A.erase(it);
        }
        if(it == A.end()) e = 0;  // 该数为 0
    }
    while(A.size() < N) A += '0';
    A = A.substr(0, N);
    return e;
}

int main() {
    int N, ea, eb;
    string A, B;
    cin >> N >> A >> B;
    ea = Standardize(A, N);
    eb = Standardize(B, N);
    if(A == B && ea == eb)
        cout << "YES 0." << A << "*10^" << ea << endl;
    else
        cout << "NO 0." << A << "*10^" << ea << " 0." << B << "*10^" << eb << endl;
    return 0;
}

