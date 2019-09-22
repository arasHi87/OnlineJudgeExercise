#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=10000007;
LL n, m, ans, arr[15];
struct Matrix {
    LL mtx[15][15];
    Matrix() {
        memset(mtx, 0, sizeof mtx);
        for (LL i=0;i<=n+1;i++) {
            mtx[i][n+1]=1;
            if (i!=n+1) {
                mtx[i][0]=10;
                for (LL j=1;j<=i;j++)
                    mtx[i][j]=1;
            }
        }
    }
    void init() {
        memset(mtx, 0, sizeof mtx);
        for (LL i=0;i<=n+1;i++)
            mtx[i][i]=1;
    }
    friend Matrix operator * (Matrix x, Matrix y) {
        Matrix tmp;
        for (LL i=0;i<=n+1;i++) {
            for (LL j=0;j<=n+1;j++) {
                tmp.mtx[i][j]=0;
                for (LL k=0;k<=n+1;k++) {
                    tmp.mtx[i][j]+=x.mtx[i][k]*y.mtx[k][j]%mod;
                }
            }
        }
        return tmp;
    }
    friend Matrix operator ^ (Matrix x, LL k) {
        Matrix tmp; tmp.init();
        while (k) {
            if (k&1) tmp=tmp*x;
            k>>=1, x=x*x;
        }
        return tmp;
    }
};
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%lld%lld", &n, &m)) {
        Matrix tmp;
        arr[0]=23, arr[n+1]=3, ans=0;;
        for (LL i=1;i<=n;i++)
            scanf("%lld", arr+i);
        tmp=tmp^m;
        for (LL i=0;i<=n+1;i++)
            ans+=arr[i]*tmp.mtx[n][i];
        printf("%lld\n", ans%mod);
    }
}