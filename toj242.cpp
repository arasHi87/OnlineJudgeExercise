#include <cstdio>
using namespace std;
struct segment {
    segment *lc, *rc;
    int tag, val, sL, sR;
    // 0-> NULL 1->bull 2->yellow
    segment(): lc(NULL), rc(NULL), tag(2), val(0), sL(2), sR(2) {};
    void push() {
        if (tag) {
            lc->tag=lc->sL=lc->sR=rc->tag=rc->sL=rc->sR=tag;
            if (tag==1) lc->val=rc->val=1;
            else lc->val=rc->val=0;
            tag=0;
        }
    }
    void pull() {
        val=lc->val+rc->val;
        if (lc->sR==rc->sL && lc->sR==1) val--;
        sL=lc->sL, sR=rc->sR;
    }
};
void update(segment *root, int L, int R, int ql, int qr, int x) {
    if (ql>R || qr<L) return;
    if (ql<=L && qr>=R) {
        root->sL=root->sR=root->tag=x;
        root->val=(x==1 ? 1 : 0);
        return;
    }
    int mid=(L+R)>>1;
    if (!root->lc) root->lc=new segment();
    if (!root->rc) root->rc=new segment();
    root->push();
    update(root->lc, L, mid, ql, qr, x);
    update(root->rc, mid+1, R, ql, qr, x);
    root->pull();
}
int query(segment *root, int L, int R, int ql, int qr) {
    if (ql<=L && qr>=R) return root->val;
    int mid=(L+R)>>1;
    if (!root->lc) root->lc=new segment();
    if (!root->rc) root->rc=new segment();
    root->push();
    if (qr<=mid) return query(root->lc, L, mid, ql ,qr);
    if (ql>mid) return query(root->rc, mid+1, R, ql ,qr);
    if (root->lc->sR==1 && root->rc->sL==1) return query(root->lc, L, mid, ql ,qr)+query(root->rc, mid+1, R, ql ,qr)-1;
    return query(root->lc, L, mid, ql ,qr)+query(root->rc, mid+1, R, ql ,qr);
}
int n, q, a, b, c;
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &q);
    segment *root=new segment();
    update(root, 0, n, 0, 0, 1);
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a==1) update(root, 0, n, b, c, 1);
        else if (a==2) update(root, 0, n, b, c, 2);
        else printf("%d\n", query(root, 0, n, b, c));
    }
}