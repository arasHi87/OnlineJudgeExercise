#include <bits/stdc++.h>
using namespace std;
const int maxN=2e4+10;
int n, q, qs[maxN], pre[maxN];
vector<int> xs;
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i), xs.emplace_back(qs[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i=1;i<=n;i++)
        qs[i]=lower_bound(xs.begin(), xs.end(), qs[i])-xs.begin()+1;
    for (int i=1;i<=n;i++)
        qs[i]+=qs[i-1];
    for (int i=1, a, b;i<=q;i++) {
        scanf("%d%d", &a, &b);
        if (a>b) swap(a, b);
        printf("%d\n", qs[b]-qs[a-1]);
    }
}