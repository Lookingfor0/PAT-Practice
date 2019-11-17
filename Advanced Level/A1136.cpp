// 用string会更简单一些
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(vector<int> a) {
    for(int i = 0, j = a.size() - 1; i < j; i++, j--)
        if(a[i] != a[j]) return false;
    return true;
}

int main() {
    vector<int> a, b, c;
    char ch;
    // 这里输入结束是 '\n'
    while((ch = getchar()) != EOF && ch != '\n')
        c.push_back(ch - '0');
    int index = 0;
    bool flag = isPalindrome(c);
    while(!flag && index++ < 10) {
        b = a = c;
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i = a.size() - 1; i >= 0; i--) {
            c[i] = a[i] + b[i] + carry;
            carry = c[i] >= 10 ? (c[i] -= 10, 1) : 0;
        }
        if(carry) c.insert(c.begin(), 1);
        for(int i = 0; i < a.size(); i++)
            printf("%d", a[i]);
        printf(" + ");
        for(int i = 0; i < b.size(); i++)
            printf("%d", b[i]);
        printf(" = ");
        for(int i = 0; i < c.size(); i++)
            printf("%d", c[i]);
        printf("\n");
        flag = isPalindrome(c);
    }
    if(flag) {
        for(int i = 0; i < c.size(); i++)
            printf("%d", c[i]);
        printf(" is a palindromic number.\n");
    } else
        printf("Not found in 10 iterations.\n");
    return 0;
}

