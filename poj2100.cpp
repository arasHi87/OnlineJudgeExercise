#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
LL k;
vector<pii> ans;
bool cmp(pii lhs, pii rhs) { return lhs.s-lhs.f>rhs.s-rhs.f; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%lld", &k)) {
        LL L=1, R=1, sum=0;
        while (L*L<=k) {
            while (sum<k) sum+=R*R, R++;
            if (sum==k) ans.pb(mp(L, R));
            sum-=L*L, L++;
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", (int)ans.size());
        for (int i=0;i<(int)ans.size();i++) {
            printf("%lld", ans[i].s-ans[i].f);
            for (LL j=ans[i].f;j<ans[i].s;j++)
                printf(" %lld", j);
            puts("");
        }
        ans.clear();
    }
}