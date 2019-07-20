#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN=200+10;
const int INF=0x3f3f3f3f;
struct Edge {
	int to;
	double val;
	Edge(int a, double b): to(a), val(b) {};
};
int idx=3, jg=0, vis[maxN]; 
double x, y, cnt;
double dx[maxN], dy[maxN], dc[maxN], dis[maxN];
vector<Edge> G[maxN];
queue<int> q;
double spfa(int st, int ed) {
	for (int i=0;i<=idx;i++)
		vis[i]=0, dis[i]=INF;
	dis[st]=0; q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Edge *tmp=&G[u][i];
			int v=(*tmp).to;
			double w=(*tmp).val;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
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
	scanf("%lf%lf%lf%lf", &dx[1], &dy[1], &dx[2], &dy[2]);
	while (~scanf("%lf%lf", &x, &y)) {
		if (x==-1 && y==-1) {
			jg=0;
			continue;
		}
		if (jg) {
			double tmp=sqrt(pow(x-dx[idx-1], 2)+pow(y-dy[idx-1], 2))*60.0/40000.0;
			G[idx].push_back(Edge(idx-1, tmp));
			G[idx-1].push_back(Edge(idx, tmp));
		}
		dx[idx]=x, dy[idx]=y, idx++, jg=1;
	}
	for (int i=1;i<idx;i++) {
		for (int j=1;j<idx;j++) {
			if (i==j) continue;
			G[i].push_back(Edge(j, sqrt(pow(dx[i]-dx[j], 2)+pow(dy[i]-dy[j], 2))*60.0/10000.0));
		}
	}
	printf("%d\n", int(spfa(1, 2)+0.5));
}