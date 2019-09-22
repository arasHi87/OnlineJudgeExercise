#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e3+10;
int ans=0;
char s[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", s)) {
        int n=strlen(s);
        for (int i=0;i<n-3;i++)
            if ((s[i]=='d' || s[i]=='D') && (s[i+1]=='o' || s[i+1]=='O') && (s[i+2]=='g' || s[i+2]=='G') && (s[i+3]=='e' || s[i+3]=='E'))
                ans++;
    }
    printf("%d\n", ans);
}