#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=4e5+10;
int nxt[maxN], arr[maxN];
char sb[maxN];
void getNext(int len) {
    int j=0, k=-1; nxt[0]=-1;
    while (j<len) {
        if (k==-1 || sb[j]==sb[k]) nxt[++j]=++k;
        else k=nxt[k];
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", sb)) {
        int len=strlen(sb), idx=1;
        for (int i=0;i<=len;i++) arr[i]=0;
        getNext(len); arr[0]=len;
        while (nxt[len]!=-1)
            arr[idx++]=nxt[len], len=nxt[len];
        sort(arr, arr+idx);
        for (int i=1;i<idx;i++)
            printf("%d%c", arr[i], (i==idx-1?'\n':' '));
    }
}