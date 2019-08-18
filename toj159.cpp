#include <cstdio>
#include <vector>
#define eb emplace_back
using namespace std;
const int maxN=5e4+10;
struct segment {
    int val, lzy;
} seg[maxN<<2];
struct Edge {
    int to, val, next;
} edge[maxN<<1];
int n, m, x, y, cnt=0;
int pre[maxN], out[maxN], in[maxN], head[maxN];
inline void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}