#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=2e5+10;
int len, mid, dp[maxN<<1];
char s1[maxN], s2[maxN<<1], tmp, ch[26];
inline int max(int a, int b) { return a>b?a:b; }
inline int min(int a, int b) { return a<b?a:b; }
inline void manacher() {
    int mx=0, id=0, idx=0, n=strlen(s1); len=0;
    s2[idx++]='$', s2[idx++]='#';
    for (int i=0;i<n;i++)
        s2[idx++]=s1[i], s2[idx++]='#';
    s2[idx]='\0';
    for (int i=1;i<idx;i++) {
        dp[i]=(i<mx ? min(dp[(id<<1)-i], mx-i) : 1);
        while (s2[i-dp[i]]==s2[i+dp[i]]) dp[i]++;
        if (mx<i+dp[i]) mx=i+dp[i], id=i;
        if (len<dp[i]-1) len=dp[i]-1, mid=i;
    }
}
inline void init(int t) {
    char ex='a';
    ch[t]=ex++;
    for (int i=t+1;(i%26)!=t;i++)
        ch[i%26]=ex++;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s%s", &tmp, s1)) {
        manacher();
        if (len<2) puts("No solution!");
        else {
            int x=((mid-len+1)>>1)-1, y=x+len-1;
            printf("%d %d\n", x, y);
            init(tmp-'a');
            for (int i=mid-len+1;i<mid+len;i++)
                if (s2[i]!='#')
                    printf("%c", ch[s2[i]-'a']);
            puts("");
        }
    }
}