#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=2e6+10;
const int INF=0x3f3f3f3f;

struct node {
    int val;
    node() {val=0;}
} tree[maxN*3];

int qs[maxN];

void pull(int root) {
    tree[root].val=max(tree[root<<1].val, tree[(root<<1)+1].val);
}

void build(int root, int l, int r) {
    if (l==r) {
        tree[root].val=qs[l];
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1, l, mid);
    build((root<<1)+1, mid+1, r);
    pull(root);
}

void update(int root, int l, int r, int pos, int d) {
    if (l==r) {
        tree[root].val=d;
        return;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) update(root<<1, l ,mid, pos, d);
    else update((root<<1)+1, mid+1, r, pos, d);
    pull(root);
}

int query(int root, int l, int r, int ql, int qr) {
    if (qr<l || ql>r) return -INF;
    if (qr>=r && l>=ql) return tree[root].val;
    int mid=(l+r)>>1;
    return max(query(root<<1, l, mid, ql, qr), query((root<<1)+1, mid+1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>qs[i];
    build(1, 1, n);
    cin>>q;
    while (q--) {
        char c;
        int a, b;
        cin>>c>>a>>b;
        if (c=='Q') cout<<query(1, 1, n, a, b)/2<<'\n';
        else update(1, 1, n, a, b);
    }
}