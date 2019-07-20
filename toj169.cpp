#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e7+10;

int mp[maxN];
int dp[maxN];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++) scanf("%d", &mp[i]);
        for (int i=2;i<=n;i++) {
            int idx=i-1;
            dp[i]=0;
            while (mp[i]>mp[idx] && idx>=1) dp[i]+=dp[idx]+1, idx-=dp[idx]+1;
        }
        printf("%d", dp[1]);
        for (int i=2;i<=n;i++) printf(" %d", dp[i]);
        puts("");
    }
}