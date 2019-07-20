#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxN=2e5+10;
struct Node {
    int x, y;
} s[maxN];
int vis[maxN], seg[maxN<<4], tmp[maxN];
vector<int> v;
inline void pull(int root) {
    seg[root<<1]=seg[root<<1|1]=seg[root];
    seg[root]=0;
}
inline void build(int root, int L, int R) {
    seg[root]=0;
    if (L==R) return;
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
}
void update(int root, int L, int R, int ql, int qr, int d) {
    if (ql>R || qr<L) return;
    if (ql<=L && qr>=R) {
        seg[root]=d;
        return;
    }
    if (seg[root]) pull(root);
    int mid=(L+R)>>1;
    update(root<<1, L, mid, ql, qr, d);
    update(root<<1|1, mid+1, R, ql, qr, d);
}
void query(int root, int L, int R) {
    if (L==R && !seg[root]) return;
    if (seg[root]) {
        vis[seg[root]]=1;
        return;
    }
    int mid=(L+R)>>1;
    query(root<<1, L, mid);
    query(root<<1|1, mid+1, R);
}
int main() {
    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(vis, 0, sizeof vis);
        for (int i=1;i<=n;i++) {
            scanf("%d%d", &s[i].x, &s[i].y);
            v.push_back(s[i].x);
            v.push_back(s[i].y);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        tmp[0]=1;
        int cnt=1, ans=0;
        for (int i=1;i<(int)v.size();i++) {
            if (v[i]==v[i-1]+1) tmp[i]=++cnt;
            else {
                cnt+=2;
                tmp[i]=cnt;
            }
        }
        for (int i=1;i<=n;i++) {
            s[i].x=tmp[lower_bound(v.begin(), v.end(), s[i].x)-v.begin()];
            s[i].y=tmp[lower_bound(v.begin(), v.end(), s[i].y)-v.begin()];
        }
        build(1, 1, v.size()<<1);
        for (int i=1;i<=n;i++)
            update(1, 1, v.size()<<1, s[i].x, s[i].y, i);
        query(1, 1, v.size()<<1);
        for (int i=1;i<=n;i++)
            if (vis[i])
                ans++;
        printf("%d\n", ans);
    }
}