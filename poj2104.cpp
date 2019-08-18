#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
int n, m, a, b, c, cnt;
int qs[maxN], root[maxN];
struct segment {
    int L, R, sum;
} seg[maxN<<5];
vector<int> v;
inline int getID(int x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin()+1;
}
void update(int &x, int y, int L, int R, int pos) {
    seg[++cnt]=seg[y], seg[cnt].sum++, x=cnt;
    if (L==R) return;
    int mid=(L+R)>>1;
    if (pos<=mid) update(seg[x].L, seg[y].L, L, mid, pos);
    else update(seg[x].R, seg[y].R, mid+1, R, pos);
}
int query(int x, int y, int L, int R, int k) {
    if (L==R) return L;
    int mid=(L+R)>>1, sum=seg[seg[y].L].sum-seg[seg[x].L].sum;
    if (k<=sum) return query(seg[x].L, seg[y].L, L, mid, k);
    else return query(seg[x].R, seg[y].R, mid+1, R, k-sum);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i), v.push_back(qs[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=1;i<=n;i++)
        update(root[i], root[i-1], 1, n, getID(qs[i]));
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", v[query(root[a-1], root[b], 1, n, c)-1]);
    }
}