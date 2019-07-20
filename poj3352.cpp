#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e3+10;
struct Edge {
	int to, next;
} edge[maxN<<2];
int n, m, x, y, ans, cnt, idx, top, scc;
int dfn[maxN], low[maxN], blo[maxN], stk[maxN], dth[maxN], head[maxN], instk[maxN];
inline void init() {
	ans=cnt=idx=top=scc=0;
	mem(dth, 0, sizeof dth);
	mem(dfn, 0, sizeof dfn);
	mem(low, 0, sizeof low);
	mem(blo, 0, sizeof blo);
	mem(stk, 0, sizeof stk);
	mem(head, -1, sizeof head);
	mem(instk, 0, sizeof instk);
}
inline void addedge(int u, int v) {
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u, int id) {
	int v;
	dfn[u]=low[u]=++idx;
	stk[++top]=u;
	instk[u]=1;
	for (int i=head[u];~i;i=edge[i].next) {
		if (i==(id^1)) continue;
		v=edge[i].to;
		if (!dfn[v]) {
			tarjan(v, i);
			low[u]=min(low[u], low[v]);
		} else if (instk[v]) low[u]=min(low[u], dfn[v]);
	}
	if (low[u]==dfn[u]) {
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
	while (~scanf("%d%d", &n, &m)) {
		init();
		while (m--) {
			scanf("%d%d", &x, &y);
			addedge(x, y), addedge(y, x);
		}
		for (int i=1;i<=n;i++)
			if (!dfn[i])
				tarjan(i, -1);
		for (int i=1;i<=n;i++)
			for (int j=head[i];~j;j=edge[j].next)
				if (blo[i]!=blo[edge[j].to])
					dth[blo[i]]++;
		for (int i=1;i<=scc;i++)
			if (dth[i]==1)
				ans++;
		printf("%d\n", (ans+1)/2);
	}
}