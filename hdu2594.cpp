#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=5e4+10;
int nxt[maxN<<1], len1, len2, len;
char s1[maxN<<1], s2[maxN];
void getNext() {
    int j=0, k=-1; nxt[0]=-1;
    while (j<len) {
        if (k==-1 || s1[j]==s1[k]) nxt[++j]=++k;
        else k=nxt[k];
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s%s", s1, s2)) {
        len1=strlen(s1), len2=strlen(s2), len=len1+len2;
        strcat(s1, s2), getNext();
        int ans=nxt[len];
        while(ans>len1 || ans>len2)
            ans=nxt[ans];
        for (int i=0;i<ans;i++)
            printf("%c", s1[i]);
        if (ans) printf(" ");
        printf("%d\n", ans);
    }
}