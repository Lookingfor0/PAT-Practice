#include <iostream>

using namespace std;

int main() {
    double bets[3][3], sum = 1.0;
    int a;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%lf", &bets[i][j]);
    for(int i = 0; i < 3; i++) {
        a = 0;
        for(int j = 0; j < 3; j++) {
            if(bets[i][j] > bets[i][a])
                a = j;
        }
        switch(a) {
            case 0: printf("W "); break;
            case 1: printf("T "); break;
            case 2: printf("L "); break;
        }
        sum *= bets[i][a];
    }
    sum = (sum * 0.65 - 1) * 2;
    printf("%.2f\n", sum);
    return 0;
}

