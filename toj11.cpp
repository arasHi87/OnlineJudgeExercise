#include <cstdio>
using namespace std;
const int maxN=2e6+10;

int dp[maxN];
int mp[maxN];

int main() {
    int n; scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &mp[i]);
    for (int i=2;i<=n;i++) {
        dp[i]=0;
        for (int j=i-1;j>=1;j--)
            if (mp[j]<mp[i]) {dp[i]+=dp[j]+1; break;}
            else dp[i]++;
    }
    for (int i=1;i<=n;i++) printf("%d ", dp[i]);
    puts("");
}