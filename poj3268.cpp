#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Node {
	int to, val;
	Node(int a, int b): to(a), val(b) {};
	bool operator < (const Node &rhs) const {
		return val>rhs.val;
	}
};
int n, m, x, a, b, c, out;
int dis[maxN], vis[maxN], ans[maxN];
vector<Node> G[maxN], RG[maxN];
void dijks(int st) {
	for (int i=1;i<=n;i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<Node> pq;
	dis[st]=0;
	pq.push(Node(st, 0));
	while (!pq.empty()) {
		Node t=pq.top(); pq.pop();
		int u=t.to; vis[u]=1;
		for (int i=0;i<(int)G[u].size();i++) {
			Node *it=&G[u][i];
			if (!vis[(*it).to] && (dis[(*it).to]>dis[u]+(*it).val)) {
				dis[(*it).to]=dis[u]+(*it).val;
				pq.push(Node((*it).to, dis[(*it).to]));
			}
		}
	}
	for (int i=1;i<=n;i++)
		ans[i]+=dis[i];
}
void dijks1(int st) {
	for (int i=1;i<=n;i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<Node> pq;
	dis[st]=0;
	pq.push(Node(st, 0));
	while (!pq.empty()) {
		Node t=pq.top(); pq.pop();
		int u=t.to; vis[u]=1;
		for (int i=0;i<(int)RG[u].size();i++) {
			Node *it=&RG[u][i];
			if (!vis[(*it).to] && (dis[(*it).to]>dis[u]+(*it).val)) {
				dis[(*it).to]=dis[u]+(*it).val;
				pq.push(Node((*it).to, dis[(*it).to]));
			}
		}
	}
	for (int i=1;i<=n;i++)
		ans[i]+=dis[i];
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d%d%d", &n, &m, &x)) {
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(Node(b, c));
			RG[b].push_back(Node(a, c));
		}
		dijks(x); dijks1(x);
		for (int i=1;i<=n;i++)
			out=max(ans[i], out);
		printf("%d\n", out);
	}
}