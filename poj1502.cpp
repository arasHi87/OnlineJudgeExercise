#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e2+10;
const int INF=0x3f3f3f3f;
struct Edge {
	int to, val;
	Edge(int a, int b): to(a), val(b) {};
};
int n, ans=0;
int vis[maxN], dis[maxN];
char s[10];
vector<Edge> G[maxN];
queue<int> q;
int spfa(int st) {
	ans=0;
	for (int i=0;i<=n;i++)
		vis[i]=0, dis[i]=INF;
	while (!q.empty()) q.pop();
	dis[st]=0, q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Edge *tmp=&G[u][i];
			int v=(*tmp).to, w=(*tmp).val;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
		ans=max(ans, dis[i]);
	return ans;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d", &n)) {
		for (int i=2;i<=n;i++) {
			for (int j=1;j<i;j++) {
				scanf("%s", s);
				if (s[0]!='x') {
					G[i].push_back(Edge(j, atoi(s)));
					G[j].push_back(Edge(i, atoi(s)));
				}
			}
		}
		printf("%d\n", spfa(1));
	}
}