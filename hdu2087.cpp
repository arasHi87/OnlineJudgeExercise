#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e3+10;
int nxt[maxN];
char s[maxN], p[maxN];
void getNext() {
    int j=0, k=-1, len=strlen(p); nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[j]==p[k]) {
            j++, k++;
            if (p[j]!=p[k]) nxt[j]=k;
            else nxt[j]=nxt[k];
        } else k=nxt[k];
    }
}
int kmp() {
    int i=0, j=0, ans=0, sLen=strlen(s), pLen=strlen(p);
    getNext();
    while (i<sLen) {
        if (j==-1 || s[i]==p[j]) i++, j++;
        else j=nxt[j];
        if (j==pLen) j=0, ans++;
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", s) && s[0]!='#') {
        scanf("%s", p);
        printf("%d\n", kmp());
    }
}