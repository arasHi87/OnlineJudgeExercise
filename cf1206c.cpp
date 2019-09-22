#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
int n, qs[maxN<<1];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    if (n%2==0) puts("NO");
    else {
        puts("YES");
        for (int i=1;i<=n;i++) qs[i]=(i<<1)-1, qs[i+n]=i<<1;
        for (int i=2;i<=n;i+=2) swap(qs[i], qs[i+n]);
        for (int i=1;i<=(n<<1);i++) printf("%d%c", qs[i], (i==(n<<1)?'\n':' '));
    }
}