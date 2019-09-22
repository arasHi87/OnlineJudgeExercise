#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;
int n;
int qs[maxN], L[maxN], R[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        memset(L, 0x3f, sizeof L);
        memset(R, 0x3f, sizeof R);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        for (int i=1;i<=n;i++) {
            int p=lower_bound(L+1, L+1+n, qs[i])-L;
            L[p]=qs[i];
        }
        for (int i=1;i<=n;i++)
            printf("%d ", L[i]); puts("");
    }    
}