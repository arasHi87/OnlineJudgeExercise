#include <cstdio>
using namespace std;
int x1, x2, y1, y2, x, y, W, H;
double tmp;
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);
    W=x2-x1, H=y2-y1;
    if (x<x1) tmp+=(x1-x)*H/2.0;
    if (x>x2) tmp+=(x-x2)*H/2.0;
    if (y<y1) tmp+=(y1-y)*W/2.0;
    if (y>y2) tmp+=(y-y2)*W/2.0;
    printf("%.1f\n", W*H+tmp);
}