#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int q;
LL n, m;
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld", &n, &m);
        vector<int> v(10);
        for (int i=1;i<=10;i++)
            v[i]=(i*m)%10;
    }
}