#include <cstdio>
using namespace std;
int n, x;
inline int abs(int a) { return a>=0?a:-a; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    int a=0, b=1;
    long long ans=0;
    while (n--) {
        scanf("%d", &x);
        if (x<0) a++;
        if (!x) b=0;
        ans+=abs(abs(x)-1);
    }
    a=(a&1?1:0)*b;
    printf("%lld\n", ans+a+a);
}