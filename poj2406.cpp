#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10;
int nxt[maxN];
char p[maxN];
int getNext(int len) {
    int j=0, k=-1; nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[j]==p[k]) nxt[++j]=++k;
        else k=nxt[k];
    }
    return len-nxt[len];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", p) && p[0]!='.') {
        int len=strlen(p), ans=getNext(len);
        if (len%ans==0) printf("%d\n", len/ans);
        else puts("1");
    }
}