#include <cstdio>
using namespace std;
int n, m, x, mxa, mxb;
inline int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    while (n--)
        scanf("%d", &x), mxa=max(mxa, x);
    scanf("%d", &m);
    while (m--)
        scanf("%d", &x), mxb=max(mxb, x);
    printf("%d %d\n", mxa, mxb);
}