#include <cstdio>
using namespace std;
const double PI=3.1415926535897932;
const double esp=1e-6;
const int maxN=1e4+10;
int t, n, f;
double qs[maxN];
bool chk(double x) {
    int sum=0;
    for (int i=1;i<=n;i++)
        sum+=qs[i]*qs[i]*PI/x;
    return sum>=f+1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &f);
        for (int i=1;i<=n;i++)
            scanf("%lf", qs+i);
        double L=0, R=1e9+10, mid;
        while (R-L>esp) {
            mid=(L+R)/2;
            if (chk(mid)) L=mid;
            else R=mid;
        }
        printf("%.4lf\n", L);
    }
}