#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=1e6+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef long long LL;
struct Edge {
	int to, next;
	LL w;
} edge[maxN];
int t, n, m, cnt;
int vis[maxN], head[maxN], in[maxN][3];
LL dis[maxN], ans=0;
queue<int> q;
void addedge(int u, int v, LL w) {
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void init() {
	cnt=0;
	for (int i=0;i<=maxN-1;i++)
		dis[i]=INF, vis[i]=0, head[i]=-1;
}
void spfa(int st) {
	dis[st]=0, q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=head[u];~i;i=edge[i].next) {
			int v=edge[i].to;
			LL w=edge[i].w;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if (!vis[v]) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
		ans+=dis[i];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		ans=0;
		init();
		for (int i=1;i<=m;i++) {
			scanf("%d%d%d", &in[i][0], &in[i][1], &in[i][2]);
			addedge(in[i][0], in[i][1], in[i][2]);
		}
		spfa(1);
		init();
		for (int i=1;i<=m;i++)
			addedge(in[i][1], in[i][0], in[i][2]);
		spfa(1);
		printf("%lld\n", ans);
	}
}