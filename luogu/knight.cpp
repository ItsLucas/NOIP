#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    char c;
    bool s = true;
    node(char c = '.', bool s = true) : c(c), s(s) {}
};

node m[51][51];
int n;
pair<int,int> p;
/*
.表示空
O表示白骑士
C表示黑城堡
K表示黑骑士
B表示黑主教
Q表示黒皇后
X表示黑国王
P表示黑士兵
*/
void init(int i, int j, char c) { //i:vert j:hori
    switch (c) {
    case '.':
        m[i][j].s = true;
        break;
    case 'O':
        p = make_pair(i,j);
        m[i][j].s = true;
        break;
    case 'C':
        for(int k=1;k<=n;k++) {
            m[k][j].s = false;
        }
        for(int k=1;k>=n;k++) {
            m[i][k].s = false;
        }
        break;
    case 'K':
    case 'B':
    case 'Q':
    case 'X':
    case 'P':
    default:
        break;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%c", &m[i][j].c);
            init(i, j, m[i][j].c);
        }
    }
}