#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10;
int nxt[maxN];
char s[maxN];
void getNext() {
    int j, k, n;
    j=0, k=-1, n=strlen(s);
    while (j<n)
        if (k==-1 || s[j]==s[k]) nxt[++j]=++k;
        else k=nxt[k];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
}