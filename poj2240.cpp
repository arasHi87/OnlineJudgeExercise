#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const int maxN=30+5;
struct Edge {
	int to;
	double val;
	Edge(int a, double b): to(a), val(b) {};
};
int n, m, a, b, kase=1;
int vis[maxN], num[maxN];
double x, dis[maxN];
char s[20], t[20];
map<string, int> mp;
vector<Edge> G[maxN];
queue<int> q;
bool spfa(int st) {
	for (int i=0;i<=n;i++)
		vis[i]=0, dis[i]=0, num[i]=0;
	while (!q.empty()) q.pop();
	dis[st]=1, q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Edge *tmp=&G[u][i];
			int v=(*tmp).to;
			double w=(*tmp).val;
			if (dis[u]*w>dis[v]) {
				dis[v]=dis[u]*w;
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
					num[v]++;
				}
				if (num[v]>n) return true;
			}
		}
	}
	return false;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d", &n) && n) {
		for (int i=0;i<=n;i++)
			G[i].clear();
		for (int i=1;i<=n;i++) {
			scanf("%s", s);
			mp[string(s)]=i;
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%s%lf%s", s, &x, t);
			a=mp[string(s)], b=mp[string(t)];
			G[a].push_back(Edge(b, x));
		}
		if (spfa(1)) printf("Case %d: Yes\n", kase);
		else printf("Case %d: No\n", kase);
		kase++;
	}
}