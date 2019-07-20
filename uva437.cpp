#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN=50;

struct block {
    int L, W, H;
} dat[maxN];

int LIS[maxN];

int main() {
    int n, kase=1;
    while (scanf("%d", &n) && n) {
        int a, b, c, idx=1, MAX=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d", &a, &b, &c);
            dat[idx++] = {a, b, c};
            dat[idx++] = {a, c, b};
            dat[idx++] = {b, a, c};
            dat[idx++] = {b, c, a};
            dat[idx++] = {c, a, b};
            dat[idx++] = {c, b, a};
        }
        sort(dat+1, dat+idx, [] (const block &x, const block &y) {
            if (x.L==y.L) return x.W<y.W;
            else return x.L<y.L;
        });
        for (int i=1;i<idx;i++) {
            LIS[i]=dat[i].H;
            for (int j=1;j<i;j++)
                if (dat[i].L>dat[j].L && dat[i].W>dat[j].W && LIS[j]+dat[i].H>LIS[i])
                    LIS[i]=LIS[j]+dat[i].H;
            if (LIS[i]>MAX) MAX=LIS[i];
        }
        printf("Case %d: maximum height = %d\n", kase++, MAX);
    }
}