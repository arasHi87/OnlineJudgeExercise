#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=1e2+10;
struct Node {
	int to;
	double R, C;
	Node(int _to, double _R, double _C): to(_to), R(_R), C(_C) {};
};
int n, m, s, x, y, vis[maxN];
double v, a, b, c, d, dis[maxN];
vector<Node> G[maxN];
queue<int> q;
bool spfa(int st) {
	for (int i=0;i<=n;i++)
		vis[i]=0, dis[i]=0;
	dis[st]=v;
	q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Node *tmp=&G[u][i];
			int to=(*tmp).to;
			double C=(*tmp).C, R=(*tmp).R;
			if (dis[to]<(dis[u]-C)*R) {
				dis[to]=(dis[u]-C)*R;
				if (!vis[to]) {
					q.push(to);
					vis[to]=1;
				}
			}
			if (dis[st]>v) return true;
		}
	}
	return false;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d%d%d%lf", &n, &m, &s, &v);
	while (m--) {
		scanf("%d%d%lf%lf%lf%lf", &x, &y, &a, &b, &c, &d);
		G[x].push_back(Node(y, a, b));
		G[y].push_back(Node(x, c, d));
	}
	if (spfa(s)) printf("YES\n");
	else printf("NO\n");
}