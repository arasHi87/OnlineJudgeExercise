#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e3+10;
const int INF=0x7f7f7f7f;
struct Edge {
	int u, v, w;
} E[maxN*maxN+maxN*10];
struct Node {
	int x, y, z;
} N[maxN];
int in[maxN], id[maxN], vis[maxN], pre[maxN];
int dmst(int root, int n, int m) {
	int ret=0, cnt=0, u, v, w;
	while (true) {
		for (int i=0;i<n;i++) in[i]=INF;
		for (int i=0;i<m;i++) {
			u=E[i].u, v=E[i].v, w=E[i].w;
			if (u!=v && w<in[v])
				pre[v]=u, in[v]=w;
		}
		for (int i=0;i<n;i++)
			if (i!=root && in[i]==INF)
				return -1;
		mem(vis, -1, sizeof vis);
		mem(id, -1, sizeof id);
		in[root]=0, cnt=0;
		for (int i=0;i<n;i++) {
			ret+=in[i], v=i;
			while (vis[v]!=i && id[v]==-1 && v!=root)
				vis[v]=i, v=pre[v];
			if (v!=root && id[v]==-1) {
				for (u=pre[v];u!=v;u=pre[u])
					id[u]=cnt;
				id[v]=cnt++;
			}
		}
		if (cnt==0) break;
		for (int i=0;i<n;i++)
			if (id[i]==-1)
				id[i]=cnt++;
		for (int i=0;i<m;i++) {
			v=E[i].v;
			E[i].v=id[E[i].v];
			E[i].u=id[E[i].u];
			if (E[i].u!=E[i].v)
				E[i].w-=in[v];
		}
		n=cnt;
		root=id[root];
	}
	return ret;
}
inline int dis(int x1, int y1, int z1, int x2, int y2, int z2) {
	return abs(x2-x1)+abs(y2-y1)+abs(z2-z1);
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	int n, x, y, z, k, v, idx=0;
	while (~scanf("%d%d%d%d", &n, &x, &y, &z) && (n+x+y+z)) {
		idx=0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d", &N[i].x, &N[i].y, &N[i].z);
			E[idx].u=0, E[idx].v=i, E[idx++].w=N[i].z*x;
		}
		for (int i=1;i<=n;i++) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &v);
				E[idx].u=i, E[idx].v=v, E[idx].w=dis(N[i].x, N[i].y, N[i].z, N[v].x, N[v].y, N[v].z)*y;
				if (N[v].z>N[i].z) E[idx].w+=z; idx++;
			}
		}
		printf("%d\n", dmst(0, n+1, idx));
	}
}