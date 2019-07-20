#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=5e2+10;
const int INF=0x3f3f3f3f;
struct Node {
	int to, val;
	Node(int a, int b): to(a), val(b) {};
};
int f, n, m, w, s, e, t;
int vis[maxN], dis[maxN], num[maxN];
vector<Node> G[maxN];
queue<int> q;
bool spfa(int st) {
	for (int i=1;i<=n;i++)
		vis[i]=0, dis[i]=INF, num[i]=0;
	while (!q.empty()) q.pop();
	dis[st]=0;
	q.push(st);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for (int i=0;i<(int)G[u].size();i++) {
			Node *tmp=&G[u][i];
			int v=(*tmp).to, p=(*tmp).val;
			if (dis[v]>dis[u]+p) {
				dis[v]=dis[u]+p;
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
					num[v]++;
				}
			}
			if (num[v]>n) return true;
		}
	}
	return false;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &f);
	while (f--) {
		scanf("%d%d%d", &n, &m, &w);
		for (int i=1;i<=n;i++)
			G[i].clear();
		while (m--) {
			scanf("%d%d%d", &s, &e, &t);
			G[s].push_back(Node(e, t));
			G[e].push_back(Node(s, t));
		}
		while (w--) {
			scanf("%d%d%d", &s, &e, &t);
			G[s].push_back(Node(e, -t));
		}
		if (spfa(1)) puts("YES");
		else puts("NO");
	}
}