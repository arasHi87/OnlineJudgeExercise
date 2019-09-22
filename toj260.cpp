#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxN=23000+10;
const int maxQ=2e5+10;
int BLOCK_SIZE;
struct Query {
    int L, R, id, bk;
    Query() {}
    Query(int _L, int _R, int _id): L(_L), R(_R), id(_id){
        bk=L/BLOCK_SIZE;
    }
    bool operator < (Query const &rhs) const {
        return bk==rhs.bk ? R<rhs.R : L<rhs.L;
    }
} Q[maxQ];
int n, q, sz, tmp;
int qs[maxN], bit[maxN], ans[maxN];
vector<int> xs;
inline int lowbit(int x) { return x&(-x); }
inline int sum(int x, int d) {
    int res=0;
    while (x) {
        res+=bit[x];
        x-=lowbit(x);
    }
}
inline void add(int x, int d) {
    while (x<=n) {
        bit[x]+=d;
        x+=lowbit(x);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &q), BLOCK_SIZE=sqrt(n);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i), xs.emplace_back(qs[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i=1;i<=n;i++)
        qs[i]=lower_bound(xs.begin(), xs.end(), qs[i])-xs.begin()+1;
    for (int i=1, L, R;i<=q;i++) {
        scanf("%d%d", &L, &R);
        if (L>R) swap(L, R);
        Q[i]=Query(L, R, i);
    }
    sort(Q+1, Q+1+q);
    for (int i=1, L=1, R=0;i<=q;i++) {
        Query &q=Q[i];
    }
}