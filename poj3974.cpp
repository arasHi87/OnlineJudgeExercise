#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10;
int t, kase=1, dp[maxN<<1];
char s1[maxN], s2[maxN<<1];
inline int max(int a, int b) { return a>b?a:b; }
inline int min(int a, int b) { return a<b?a:b; }
inline int manacher() {
    int mx=0, id=0, ans=0, idx=0, n=strlen(s1);
    s2[idx++]='$', s2[idx++]='#';
    for (int i=0;i<n;i++)
        s2[idx++]=s1[i], s2[idx++]='#';
    s2[idx]='\0';
    for (int i=1;i<idx;i++) {
        dp[i]=(i<mx ? min(dp[(id<<1)-i], mx-i) : 1);
        while (s2[i-dp[i]]==s2[i+dp[i]]) dp[i]++;
        if (mx<i+dp[i]) mx=i+dp[i], id=i;
        ans=max(ans, dp[i]-1);
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", s1) && strcmp(s1, "END"))
        printf("Case %d: %d\n", kase++, manacher());
}