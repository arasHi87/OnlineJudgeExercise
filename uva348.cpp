#include <iostream>
#include <cstring>
#include <algorithm>
#define T dp(i, k)+dp(k+1, j)+x[i]*y[k]*y[j]
using namespace std;
const int maxN=15;
const int INF=0x3f3f3f3f;

int f[maxN][maxN],
    pre[maxN][maxN],
    x[maxN], y[maxN],
    n, kase=1;

void print(int i, int j) {
    int k=pre[i][j];
    if (k) {
        printf("(");
        print(i, k);
        printf(" x ");
        print(k+1, j);
        printf(")");
    } else {
        printf("A%d", i);
    }
}

int dp(int i, int j) {
    if (f[i][j]!=INF) return f[i][j];
    for (int k=i;k<j;k++)
        if (f[i][j]>T)
            f[i][j]=T,
            pre[i][j]=k;
    return f[i][j];
}

int main() {
    while (~scanf("%d", &n) && n) {
        memset(f, INF, sizeof f);
        memset(pre, 0, sizeof pre);
        for (int i=1;i<=n;i++)
            scanf("%d%d", x+i, y+i), f[i][i]=0;
        dp(1, n);
        printf("Case %d: ", kase++);
        print(1, n);
        puts("");
    }
}