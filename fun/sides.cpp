#include <cstdio>
#include <iostream>

using namespace std;

int dice1[7], dice2[7], alice, bob;

int cal() {
    alice = 0, bob = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (dice1[i] == dice2[j]) {
                alice++;
                bob++;
            } else if (dice1[i] < dice2[j]) {
                bob++;
            } else {
                alice++;
            }
        }
    }
    if (alice > bob)
        return 1;
    else if (alice < bob)
        return 2;
    else
        return 3;
}

int main() {
    freopen("sides.in", "r", stdin);
    freopen("sides.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= 6; j++) {
            scanf("%d", &dice1[j]);
        }
        for (int j = 1; j <= 6; j++) {
            scanf("%d", &dice2[j]);
        }
        switch (cal()) {
        case 1:
            printf("Alice\n");
            break;
        case 2:
            printf("Bob\n");
            break;
        case 3:
            printf("Tie\n");
            break;
        default:
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}