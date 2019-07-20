#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1005;
const int INF=0x3f3f3f3f;
struct Node {
	int to, val;
	Node(int _to, int _val): to(_to), val(_val) {};
	bool operator < (const Node &rhs) const {
		return val>rhs.val;
	}
};
int n, m, x, y, z;
int vis[maxN], dis[maxN];
vector<Node> G[maxN];
int dijks(int st, int ed) {
	dis[st]=0;
	priority_queue<Node> pq;
	pq.push(Node(st, 0));
	while (!pq.empty()) {
		Node nd=pq.top(); pq.pop();
		int v=nd.to;
		vis[v]=1;
		for (int i=0;i<(int)G[v].size();i++) {
			Node it=G[v][i];
			if (!vis[it.to] && (dis[it.to]>dis[v]+it.val)) {
				dis[it.to]=dis[v]+it.val;
				pq.push(Node(it.to, dis[it.to]));
			}
		}
	}
	return dis[ed];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d%d", &m, &n);
	for (int i=1;i<=n;i++) {
		dis[i]=INF;
		vis[i]=0;
		G[i].clear();
	}
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back(Node(y, z));
		G[y].push_back(Node(x, z));
	}
	printf("%d\n", dijks(1, n));
}