#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL n, m;
struct Matrix {
    LL mtx[10][10];
    Matrix() { memset(mtx, 0, sizeof mtx); }
    void init() {
        for (int i=1;i<=3;i++)
            mtx[i][i]=1;
    }
    friend Matrix operator * (Matrix x, Matrix y) {
        Matrix tmp;
        for (int i=1;i<=3;i++) {
            for (int j=1;j<=3;j++) {
                tmp.mtx[i][j]=0;
                for (int k=1;k<=3;k++)
                    tmp.mtx[i][j]+=(x.mtx[i][k]*y.mtx[k][j])%m;
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
        if (n==1) { printf("%lld\n", 1%m); continue; }
        if (n==2) { printf("%lld\n", 2%m); continue; }
        Matrix tmp, ans;
        tmp.mtx[1][2]=2, tmp.mtx[2][2]=tmp.mtx[3][2]=tmp.mtx[2][1]=tmp.mtx[3][3]=1;
        ans.mtx[1][1]=1, ans.mtx[1][2]=2, ans.mtx[1][3]=1;
        tmp=tmp^(n-2), ans=ans*tmp;
        printf("%lld\n", ans.mtx[1][2]%m); 
    }
}