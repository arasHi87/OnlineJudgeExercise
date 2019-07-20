#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10;
int n, idx=1, nxt[maxN];
char p[maxN];
void getNext() {
    int j=0, k=-1, len=strlen(p); nxt[0]=-1;
    while (j<len) {
        if (k==-1 || p[j]==p[k]) nxt[++j]=++k;
        else k=nxt[k];
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        printf("Test case #%d\n", idx++);
        scanf("%s", p); getNext();
        for (int i=2;i<=n;i++) {
            int tmp=i-nxt[i];
            if (i%tmp==0 && i/tmp>1)
                printf("%d %d\n", i, i/tmp);
        }
        puts("");
    }
}