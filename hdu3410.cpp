#include <cstdio>
using namespace std;
typedef long long LL;
const int maxN=5e4+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
int t, n;
LL ansL[maxN], ansR[maxN], arr[maxN], stk[maxN];
inline void FindL() {
    int top=-1;
    for (int i=1;i<=n;i++) {
        LL ans=-INF, pos;
        while (top!=-1 && arr[stk[top]]<arr[i]) {
            if (arr[stk[top]]>ans)
                ans=arr[stk[top]], pos=stk[top];
            top--;
        }
        ansL[i]=(ans==-INF ? 0 : pos), stk[++top]=i; 
    }
}
inline void FindR() {
    int top=-1;
    for (int i=n;i>=1;i--) {
        LL ans=-INF, pos;
        while (top!=-1 && arr[stk[top]]<arr[i]) {
            if (arr[stk[top]]>ans)
                ans=arr[stk[top]], pos=stk[top];
            top--;
        }
        ansR[i]=(ans==-INF ? 0 : pos), stk[++top]=i; 
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
            scanf("%lld", arr+i);
        FindL(), FindR();
        printf("Case %d:\n", kase);
        for (int i=1;i<=n;i++)
            printf("%lld %lld\n", ansL[i], ansR[i]);
    }
}