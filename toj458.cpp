#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e6+10;
struct Edge {
	int to, next;
} edge[maxN<<2];
int n, m, k, cnt, idx, st, ed, top, scc, ans, mp[1005][1005];
int low[maxN], dfn[maxN], head[maxN], instk[maxN], stk[maxN], blo[maxN], in[maxN];
int d[8][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
inline int xy2d(int x, int y) {
	return (x-1)*m+y;
}
inline void addedge(int u, int v) {
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u) {
	int v;
	dfn[u]=low[u]=++idx;
	instk[u]=1;
	stk[++top]=u;
	for (int i=head[u];~i;i=edge[i].next) {
		v=edge[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u], low[v]);
		} else if (instk[v]) low[u]=min(low[u], dfn[v]);
	}
	if (dfn[u]==low[u]) {
		scc++;
		do {
			v=stk[top--];
			instk[v]=0;
			blo[v]=scc;
		} while (u!=v);
	}
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d%d", &n, &m);
	cnt=idx=top=scc=ans=0;
	for (int i=1;i<=n*m;i++) head[i]=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d", &mp[i][j]);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (mp[i][j]) {
				if (mp[i][j]==1) st=0, ed=3;
				else if (mp[i][j]==2) st=4, ed=7;
				else st=0, ed=7;
				for (int k=st;k<=ed;k++) {
					int nx=i+d[k][0], ny=j+d[k][1];
					if (nx<1 || ny<1 || nx>n || ny>m || !mp[nx][ny]) continue;
					addedge(xy2d(i ,j), xy2d(nx, ny));
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!dfn[xy2d(i, j)] && mp[i][j])
				tarjan(xy2d(i, j));
	for (int i=1;i<=n*m;i++) {
		for (int j=head[i];~j;j=edge[j].next) {
			int v=edge[j].to;
			if (blo[i]!=blo[v]) {
				in[blo[v]]++;
			}
		}
	}
	for (int i=1;i<=scc;i++)
		if (!in[i]) ans++;
	printf("%d\n", ans);
}