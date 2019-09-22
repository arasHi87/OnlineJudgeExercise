#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
int n;
LL a, b;
struct Matrix {
    LL mtx[5][5];
    Matrix() {
        memset(mtx, 0, sizeof mtx);
        for (int i=1;i<=2;i++)
            mtx[i][i]=1;
    }
    Matrix(int a, int b, int c, int d) { mtx[1][1]=a, mtx[1][2]=b, mtx[2][1]=c, mtx[2][2]=d; }
    void Dbg() {
        for (int i=1;i<=2;i++) {
            for (int j=1;j<=2;j++)
                printf("%lld ", mtx[i][j]);
            puts("");
        }
    }
    friend Matrix operator * (Matrix x, Matrix y) {
        Matrix tmp;
        for (int i=1;i<=2;i++) {
            for (int j=1;j<=2;j++) {
                tmp.mtx[i][j]=0;
                for (int k=1;k<=2;k++) {
                    tmp.mtx[i][j]+=(x.mtx[i][k]*y.mtx[k][j])%mod;
                }
            }
        }
        return tmp;
    }
    friend Matrix operator ^ (Matrix x, LL k) {
        Matrix tmp;
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
    Matrix tmp(1, -1, 1, 0);
    scanf("%lld%lld%d", &a, &b, &n);
    if (n==1) return printf("%lld\n", (a+mod)%mod), 0;
    if (n==2) return printf("%lld\n", (b+mod)%mod), 0;
    tmp=tmp^(n-2);
    LL ans=b*tmp.mtx[1][1]+a*tmp.mtx[1][2];
    printf("%lld\n", ((ans+mod)%mod+mod)%mod);
}