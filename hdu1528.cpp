#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=60;
struct Edge {
    int to, next;
} edge[maxN<<1];
int t, n, idx, cnt;
int vis[maxN], mth[maxN], head[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline int getScore(char *s) {
    printf("%c %c\n", *s, *++s);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    // scanf("%d", &t);
    // while (t--) {
    //     scanf("%d", &n);
    // }
    char test[2]={'1', '2'};
    printf("%d\n", getScore("12"));
}