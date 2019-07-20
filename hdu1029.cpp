#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e6+10;
int n, qs[maxN];
int main() {
    #ifdef local    
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        sort(qs+1, qs+1+n);
        printf("%d\n", qs[(n>>1)+1]);
    }
}