#include <cstdio>
using namespace std;
const double PI=3.1415926535897932;
const double eps=1e-8;
double r, R, H, V;
int t;
double chk(double x) {
    double u=(R-r)*x/H+r;
    return PI*x*(r*r+u*u+r*u)/3;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (~scanf("%lf%lf%lf%lf", &r, &R, &H, &V)) {
        double L=0.0, R=100.0, mid;
        while (R-L>eps) {
            mid=(L+R)/2;
            if (chk(mid)-V>eps) R=mid;
            else L=mid;
        }
        printf("%.6lf\n", L);
    }
}