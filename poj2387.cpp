// #include <cstdio>
// #include <cstring>
// #include <queue>
// #include <vector>
// #include <algorithm>
// using namespace std;
// const int maxN=1005;
// const int INF=0x3f3f3f3f;
// struct Node {
// 	int to, val;
// 	Node(int _to, int _val): to(_to), val(_val) {};
// 	bool operator < (const Node &rhs) const {
// 		return val>rhs.val;
// 	}
// };
// int n, m, x, y, z;
// int vis[maxN], dis[maxN];
// vector<Node> G[maxN];
// int dijks(int st, int ed) {
// 	dis[st]=0;
// 	priority_queue<Node> pq;
// 	pq.push(Node(st, 0));
// 	while (!pq.empty()) {
// 		Node nd=pq.top(); pq.pop();
// 		int v=nd.to;
// 		vis[v]=1;
// 		for (int i=0;i<(int)G[v].size();i++) {
// 			Node it=G[v][i];
// 			if (!vis[it.to] && (dis[it.to]>dis[v]+it.val)) {
// 				dis[it.to]=dis[v]+it.val;
// 				pq.push(Node(it.to, dis[it.to]));
// 			}
// 		}
// 	}
// 	return dis[ed];
// }
// int main() {
// 	#ifdef local
// 		freopen("in", "r", stdin);
// 	#endif
// 	scanf("%d%d", &m, &n);
// 	for (int i=1;i<=n;i++) {
// 		dis[i]=INF;
// 		vis[i]=0;
// 		G[i].clear();
// 	}
// 	while (m--) {
// 		scanf("%d%d%d", &x, &y, &z);
// 		G[x].push_back(Node(y, z));
// 		G[y].push_back(Node(x, z));
// 	}
// 	printf("%d\n", dijks(1, n));
// }

// #include <cstdio>
// #include <queue>
// #include <cstring>
// using namespace std;
// const int maxN=4e3+10;
// const int INF=0x3f3f3f3f;
// struct Edge {
// 	int to, next, val;
// 	Edge(): to(0), next(0), val(0) {};
// 	Edge(int _to, int _next, int _val): to(_to), next(_next), val(_val) {};
// } edge[maxN];
// struct Node {
// 	int to, val;
// 	Node(int _to, int _val): to(_to), val(_val) {};
// 	bool operator < (const Node &rhs) const {
// 		return val>rhs.val;
// 	}
// };
// int n, t, x, y, z, cnt=0;
// int dis[maxN], vis[maxN], head[maxN];
// priority_queue<Node> pq;
// void addedge(int u, int v, int w) {
// 	edge[cnt].to=v;
// 	edge[cnt].val=w;
// 	edge[cnt].next=head[u];
// 	head[u]=cnt++;
// }
// int dijks(int st, int ed) {
// 	memset(dis, INF, sizeof dis);
// 	memset(vis, 0, sizeof vis);
// 	dis[st]=0; pq.push(Node(st, 0));
// 	while (!pq.empty()) {
// 		int u=pq.top().to;
// 		pq.pop(); vis[u]=1;
// 		for (int i=head[u];~i;i=edge[i].next) {
// 			int v=edge[i].to, w=edge[i].val;
// 			if (!vis[v] && dis[v]>dis[u]+w)
// 				dis[v]=dis[u]+w,
// 				pq.push(Node(v, dis[v]));
// 		}
// 	}
// 	return dis[ed];
// }
// int main() {
// 	#ifdef local
// 		freopen("in", "r", stdin);
// 	#endif
// 	scanf("%d%d", &t, &n);
// 	memset(head, -1, sizeof head);
// 	while (t--)
// 		scanf("%d%d%d", &x, &y, &z),
// 		addedge(x, y, z), addedge(y, x, z);
// 	printf("%d\n", dijks(1, n));
// }

#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=4e3+10;
const int INF=0x3f3f3f3f;
struct Edge {
	int to, next, val;
	Edge(): to(0), next(0), val(0) {};
	Edge(int _to, int _next, int _val): to(_to), next(_next), val(_val) {};
} edge[maxN];
struct Node {
	int to, val;
	Node(int _to, int _val): to(_to), val(_val) {};
	bool operator < (const Node &rhs) const {
		return val>rhs.val;
	}
};
int n, t, x, y, z, cnt=0;
int dis[maxN], vis[maxN], head[maxN];
queue<int> q;
void addedge(int u, int v, int w) {
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int spfa(int st, int ed) {
	memset(dis, INF, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[st]=0, q.push(st);
	while (!q.empty()) {
		int u=q.front();
		q.pop(); vis[u]=0;
		for (int i=head[u];~i;i=edge[i].next) {
			int v=edge[i].to, w=edge[i].val;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if (!vis[v])
					q.push(v), vis[v]=1;
			}
		}
	}
	return dis[ed];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d%d", &t, &n);
	memset(head, -1, sizeof head);
	while (t--)
		scanf("%d%d%d", &x, &y, &z),
		addedge(x, y, z), addedge(y, x, z);
	printf("%d\n", spfa(1, n));
}