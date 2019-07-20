#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e6+10;
const int maxM=1e4+10;
int t, n, m;
int nxt[maxM], a[maxN], b[maxM];
void getNext() {
    int j=0, k=-1; nxt[0]=-1;
    while (j<m) {
        if (k==-1 || b[j]==b[k]) {
            j++, k++;
            if (b[j]!=b[k]) nxt[j]=k;
            else nxt[j]=nxt[k];
        } else k=nxt[k];
    }
}
int kmp() {
    int i=0, j=0; getNext();
    while (i<n && j<m) {
        if (j==-1 || a[i]==b[j]) i++, j++;
        else j=nxt[j];
    }
    if (j==m) return i-j+1;
    else return -1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        for (int i=0;i<m;i++) scanf("%d", b+i);
        printf("%d\n", kmp());
    }
}