#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=60+10;
int t, n, nxt[maxN];
char a[15][maxN], b[maxN], tmp[maxN], ans[maxN];
// inline void getNext(const char *p) {
//     int j=0, k=-1, len=strlen(p); nxt[0]=-1;
//     while (j<len) {
//         if (k==-1 || p[j]==p[k]) {
//             j++, k++;
//             if (p[j]!=p[k]) nxt[j]=k;
//             else nxt[j]=nxt[k];
//         } else k=nxt[k];
//     }
// }
// inline int kmp(const char *s, const char *p) {
//     int i=0, j=0, sLen=strlen(s), pLen=strlen(p);
//     while (i<sLen && j<pLen) {
//         if (s[i]==p[j]) i++, j++;
//         else j=nxt[j];
//     }
//     if (j==pLen) return 1;
//     else return 0;
// }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(ans, '\0', sizeof ans);
        for (int i=1;i<=n;i++)
            scanf("%s", a[i]);
        int cnt=0;
        for (int len=1;len<=60;len++) {
            for (int pos=0;pos<=60-len;pos++) {
                int idx=0, flag=1, now=pos;
                while (now<pos+len)
                    tmp[idx++]=a[1][now++];
                tmp[idx]='\0';
                for (int i=2;i<=n;i++) {
                    if (!strstr(a[i], tmp)) {
                        flag=0;
                        break;
                    }
                }
                if (flag) {
                    cnt=1;
                    if (strlen(tmp)>strlen(ans)) strcpy(ans, tmp);
                    else if (strcmp(ans, tmp)>0) strcpy(ans, tmp);
                }
                if (!cnt) break;
            }
        }
        if (strlen(ans) < 3) printf("no significant commonalities\n");
        else printf("%s\n", ans);
    }
}