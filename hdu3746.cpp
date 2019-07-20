#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
int n, nxt[maxN];
char p[maxN];
int getNext() {
    int j=0, k=-1, len=strlen(p); nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[j]==p[k]) {
            j++, k++;
            if (p[k]!=p[j]) nxt[j]=k;
            else nxt[j]=nxt[k];
        } else k=nxt[k];
    }
    int n=len-nxt[len];
    if (len%n==0 && len!=n) return 0;
    else return n-len%n;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    while (n--) {
        scanf("%s", p);
        printf("%d\n", getNext());
    }
}