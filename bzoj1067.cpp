#include <bits/stdc++.h>
using namespace std;
const int maxN=5e4+10;
int n, m;
int Y[maxN], R[maxN], mx[maxN][25];
inline int read() {
    char c=getchar(); int x=0, f=1;
    while (c<'0' || c>'9') { if (c=='-') f=-1; c=getchar(); }
    while (c>='0' && c<='9') x=(x<<3)+(x<<1)+(c-'0'), c=getchar();
    return x*f;
}
inline int max(int a, int b) { return a>b?a:b; }
inline int getPos(int x) {
    int L=1, R=n, mid, res;
    while (L<=R) {
        mid=(L+R)>>1;
        x>=Y[mid] ? L=mid+1, res=mid : R=mid-1; 
    }
    return res;
}
inline int query(int L, int R) {
    if (L>R) return -0x7fffffff;
    int q=log2(R-L+1);
    return max(mx[L][q], mx[R-(1<<q)+1][q]);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    n=read();
    for (int i=1;i<=n;i++)
        Y[i]=read(), R[i]=read(), mx[i][0]=R[i];
    for (int j=1;j<=20;j++)
        for (int i=1;i+(1<<j)<=n;i++)
            mx[i][j]=max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
    m=read();
    for (int x, y;m--;) {
        x=read(), y=read();
        int px=getPos(x), py=getPos(y);
        if (x!=Y[px] && y!=Y[py]) puts("maybe");
        else if (x!=Y[px] && y==Y[py]) query(px+1, py-1)<R[py] ? puts("maybe") : puts("false");
        else if (x==Y[px] && y!=Y[py]) query(px+1, py)<R[px] ? puts("maybe") : puts("false");
        else if (y-x!=py-px) (query(px+1, py-1)>=R[py] || R[py]>=R[px]) ? puts("false") : puts("maybe");
        else if (query(px+1, py-1)<R[py] && R[py]<R[px]) puts("true");
        else puts("false");
    }
}