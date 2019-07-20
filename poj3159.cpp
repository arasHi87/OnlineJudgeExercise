#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e5+5e4+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef long long LL;
struct Edge {
	int to, nxt;
	LL w;
} edge[maxN];
int n, m, x, y, cnt, vis[maxN], head[maxN]; 
LL z, ans, dis[maxN];
void init() {
	cnt=0;
	for (int i=1;i<=n;i++)
		head[i]=-1, dis[i]=INF, vis[i]=0;
}
void addedge(int u, int v, LL w) {
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
LL spfa(int st) {
	stack<int, vector<int>> stk;
	dis[st]=0, stk.push(st);
	while (!stk.empty()) {
		int u=stk.top(); stk.pop();
		vis[u]=0;
		for (int i=head[u];~i;i=edge[i].nxt) {
			int v=edge[i].to;
			LL w=edge[i].w;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if (!vis[v]) {
					vis[v]=1;
					stk.push(v);
				}
			}
		}
	}
	return dis[n];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d%d", &n, &m)) {
		init();
		while (m--) {
			scanf("%d%d%lld", &x, &y, &z);
			addedge(x, y, z);
		}
		printf("%lld\n", spfa(1));
	}
}