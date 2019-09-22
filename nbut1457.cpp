#include <math.h>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxN=1e5+10;
struct Node {
    int L, R, id, blk;
    bool operator < (const Node &rhs) const {
        return blk==rhs.blk ? R<rhs.R : L<rhs.L;
    }
} Q[maxN];
int n, q, m, sqn;
int qs[maxN], num[maxN];
LL tmp, ans[maxN], pow3[maxN];
inline void add(int x) { tmp-=pow3[num[x]], num[x]++, tmp+=pow3[num[x]]; }
inline void del(int x) { tmp-=pow3[num[x]], num[x]--, tmp+=pow3[num[x]]; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    for (LL i=1;i<=maxN;i++)
        pow3[i]=i*i*i;
    while (~scanf("%d", &n)) {
        vector<int> xs; sqn=sqrt(n);
        for (int i=1;i<=n;i++) {
            scanf("%d", qs+i);
            xs.emplace_back(qs[i]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end())), m=xs.size();
        for (int i=1;i<=n;i++)
            qs[i]=lower_bound(xs.begin(), xs.end(), qs[i])-xs.begin()+1;
        memset(num, 0, sizeof num);
        scanf("%d", &q);
        for (int i=1;i<=q;i++)
            scanf("%d%d", &Q[i].L, &Q[i].R), Q[i].id=i, Q[i].blk=Q[i].L/sqn;
        sort(Q+1, Q+1+q);
        for (int i=1, L=1, R=0;i<=q;i++) {
            while (L<Q[i].L) del(qs[L++]);
            while (L>Q[i].L) add(qs[--L]);
            while (R<Q[i].R) add(qs[++R]);
            while (R>Q[i].R) del(qs[R--]);
            ans[Q[i].id]=tmp;
        }
        for (int i=1;i<=q;i++)
            printf("%lld\n", ans[i]);
    }
}