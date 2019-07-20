#include <iostream>
using namespace std;
const int maxN=3e5+10;
typedef long long LL;

int c[11]={5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000}, a, b;
LL f[maxN];

void init() {
    f[0]=1;
    for (int i=0;i<11;i++)
        for (int j=c[i];j<=maxN-10;j++)
            f[j]+=f[j-(LL)c[i]];
}

int main() {
    init();
    while (~scanf("%d.%d", &a, &b)) {
        if (a==0 && b==0) break;
        int t=a*100+b;
        printf("%3d.%02d%17lld\n", a, b, f[t]);
    }
}