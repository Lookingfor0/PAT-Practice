#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, K = 0;
    double sum = 0.0, temp;
    char a[50], b[50];
    scanf("%d", &N);
    while(N--) {
        bool flag = true;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        for(int i = 0; i < strlen(a) && flag; i++)
            if(a[i] != b[i]) flag = false;
        if(flag && temp >= -1000 && temp <= 1000) {
            sum += temp;
            K++;
        } else
            printf("ERROR: %s is not a legal number\n", a);
    }
    if(K == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(K == 0)
        printf("The average of 0 numbers is Undefined");
    else
        printf("The average of %d numbers is %.2f", K, sum / K);
    return 0;
}

