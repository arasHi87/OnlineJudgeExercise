#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1005;
const int INF=0x3f3f3f3f;
struct Edge {
	int to, val;
	Edge(int a=0, int b=0): to(a), val(b) {};
	bool operator < (const Edge &rhs) const {
		return val<rhs.val;
	}
};
int t, n, m, x, y, z;
int vis[maxN], dis[maxN];
vector<Edge> G[maxN];
int dijks(int st, int ed) {
	dis[st]=INF;
	priority_queue<Edge> pq;
	pq.push(Edge(st, INF));
	while (!pq.empty()) {
		Edge e=pq.top(); pq.pop();
		int v=e.to; vis[v]=1;
		for (int i=0;i<(int)G[v].size();i++) {
			Edge tmp=G[v][i];
			if (!vis[tmp.to] && dis[tmp.to]<min(dis[v], tmp.val)) {
				dis[tmp.to]=min(dis[v], tmp.val);
				pq.push(Edge(tmp.to, dis[tmp.to]));
			}
		}
	}
	return dis[ed];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	for (int kase=1;kase<=t;kase++) {
		printf("Scenario #%d:\n", kase);
		scanf("%d%d", &n, &m);
		for (int i=1;i<=n;i++) {
			dis[i]=0;
			vis[i]=0;
			G[i].clear();
		}
		while (m--) {
			scanf("%d%d%d", &x, &y, &z);
			G[x].push_back(Edge(y, z));
			G[y].push_back(Edge(x, z));
		}
		printf("%d\n\n", dijks(1, n));
	}
}