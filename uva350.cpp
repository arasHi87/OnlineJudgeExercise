#include <iostream>
#include <memory.h>
using namespace std;
const int maxN=1e5+1;

int tmp[maxN];

int main() {
    int Z, I, M, L, cnt=1;
    while (~scanf("%d%d%d%d", &Z, &I, &M, &L) && (Z || I || M || L)) {
        memset(tmp, 0, sizeof tmp);
        int res = 0;
        L = (Z*L+I)%M;
        while (!tmp[L]) {
            tmp[L] = 1;
            L = (Z*L+I)%M;
            res++;
        }
        printf("Case %d: %d\n", cnt++, res);
    }
}