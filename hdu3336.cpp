#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=2e5+10;
int n, t, nxt[maxN];
char p[maxN];
void getNext() {
    int j=0, k=-1; nxt[0]=-1;
    while (j<n) {
        if (k==-1 || p[k]==p[j]) nxt[++j]=++k;
        else k=nxt[k];
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, p);
        int ans=n;
        getNext();
        for (int i=1;i<=n;i++) {
            int j=i;
            while (nxt[j]!=0 && nxt[j]!=-1) {
                ans=(ans+1)%10007, j=nxt[j];
            }
        }
        printf("%d\n", ans);
    }
}