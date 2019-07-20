#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=1e7;
typedef long long ll;

struct Max {
    ll MAX;
    int left, right;
} tree[maxN<<2];

ll origin[maxN];

inline void maintain(int root) {
    int LC=root<<1;
    int RC=(root<<1)+1;
    tree[root].MAX=max(tree[LC].MAX, tree[RC].MAX);
}

void build (int root, int start, int end) {
    tree[root].left=start;
    tree[root].right=end;
    if (start==end) {
        tree[root].MAX=origin[start];
        return;
    }
    int mid=(start+end)>>1;
    build(root<<1, start, mid);
    build((root<<1)+1, mid+1, end);
    maintain(root);
}

ll RmaxQ(int root, int start, int end) {
    cout << root << ' ' << tree[root].left << " " << tree[root].right << endl;
    if (start==tree[root].left && end==tree[root].right) return tree[root].MAX;
    int mid=(tree[root].left+tree[root].right)>>1;
    ll ret=-1;
    if (end<=mid) ret=max(ret, RmaxQ(root<<1, start, end));
    else if (start>=mid+1) ret=max(ret, RmaxQ((root<<1)+1, start, end));
    else {
        ll a=RmaxQ(root<<1, start, mid);
        ll b=RmaxQ((root<<1)+1, mid+1, end);
        ret=max(a, b);
    }
    return ret;
}

int main() {
    int n, q, a, b;
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++) scanf("%lld", &origin[i]);
    build(1, 1, n);
    for (int i=1;i<=q;i++) {
        scanf("%d%d", &a, &b);
        if (a>b) swap(a, b);
        printf("%lld\n", RmaxQ(1, a, b));
    }
}