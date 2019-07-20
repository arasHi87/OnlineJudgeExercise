#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e4+10;
const int maxM=1e6+10;
int n, nxt[maxM];
char s[maxM], p[maxN];
void getNext() {
    int j=0, k=-1, len=strlen(p); nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[k]==p[j]) {
            j++, k++;
            if (p[k]!=p[j]) nxt[j]=k;
            else nxt[j]=nxt[k];
        } else k=nxt[k];
    }
}
int kmp() {
    int ans=0, i=0, j=0, sLen=strlen(s), pLen=strlen(p);
    getNext();
    while (i<sLen) {
        if (j==-1 || s[i]==p[j]) i++, j++;
        else j=nxt[j];
        if (j==pLen) ans++;
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", p, s);
        printf("%d\n", kmp());
    }
}