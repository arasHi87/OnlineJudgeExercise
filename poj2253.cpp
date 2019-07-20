#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN=2e2+10;
const int INF=0x3f3f3f3f;
struct Edge {
	int to;
	double val;
	Edge(int a, double b): to(a), val(b) {};
};
struct Node {
	double x, y;
} s[maxN];
int n, vis[maxN], kase=0;
double x, y, dis[maxN];
vector<Edge> G[maxN];
queue<int> q;
double spfa(int st, int ed) {
	for (int i=0;i<=n;i++)
		vis[i]=0, dis[i]=INF;
	while (!q.empty()) q.pop();
	dis[st]=0, q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Edge *tmp=&G[u][i];
			int v=(*tmp).to;
			double w=(*tmp).val;
			if (dis[v]>max(dis[u], w)) {
				dis[v]=max(dis[u], w);
				if (!vis[v]) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[ed];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d", &n) && n) {
		for (int i=0;i<=n;i++) 
			G[i].clear(), s[i].x=s[i].y=0;
		for (int i=1;i<=n;i++) {
			scanf("%lf%lf", &x, &y);
			s[i].x=x, s[i].y=y;
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				G[i].push_back(Edge(j, sqrt(pow(s[i].x-s[j].x, 2)+pow(s[i].y-s[j].y, 2))));
			}
		}
		if (kase) puts("");
		printf("Scenario #%d\nFrog Distance = %.3lf\n", ++kase, spfa(1, 2));
	}
}