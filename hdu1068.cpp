#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e4+10;
struct Edge {
	int to, next;
} edge[maxN];
int n, cnt, idx, ans;
int vis[maxN], mth[maxN], head[maxN];
inline void addedge(int u, int v) {
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int dfs(int u) {
	for (int i=head[u];~i;i=edge[i].next) {
		int v=edge[i].to;
		if (vis[v]!=idx) {
			vis[v]=idx;
			if (mth[v]==-1 || dfs(mth[v]))
				{ mth[v]=u; return 1; }
		}
	}
	return 0;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d", &n)) {
		memset(mth, -1, sizeof mth), ans=cnt=0;
		memset(head, -1, sizeof head);
		for (int i=0, u, v, m;i<n;i++) {
			scanf("%d: (%d)", &u, &m);
			while (m--) {
				scanf("%d", &v);
				addedge(u, v);
			}
		}
		for (int i=0;i<n;i++)
			idx++, ans+=dfs(i);
		printf("%d\n", n-(ans>>1));
	}
}