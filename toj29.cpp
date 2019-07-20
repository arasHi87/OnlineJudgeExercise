#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
const int maxN=1e6+10;
const int maxM=50+10;
int t, n, nxt[maxM];
char s[maxN], p[maxM];
void getNext() {
    int j=0, k=-1, len=strlen(p); nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[k]==p[j]) {
            j++, k++;
            if (p[j]!=p[k]) nxt[j]=k;
            else nxt[j]=nxt[k];
        } else k=nxt[k];
    }
}
int kmp() {
    int i=0, j=0, sLen=strlen(s), pLen=strlen(p);
    getNext();
    while (i<sLen && j<pLen) {
        if (j==-1 || s[i]==p[j]) i++, j++;
        else j=nxt[j];
    }
    if (j==pLen) return 1;
    else return 0;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%s%d", s, &n);
        while (n--) {
            scanf("%s", p);
            if (kmp()) printf("y\n");
            else printf("n\n");
        }
    }
}