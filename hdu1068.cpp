#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;
int n, m, a, b, cnt=0, ans;
int vis[maxN], mth[maxN];
vector<int> G[maxN];
int find(int x) {
	for (int i=0;i<(int)G[x].size();i++) {
		if (!vis[G[x][i]]) {
			vis[G[x][i]]=1;
			if (mth[G[x][i]]==-1 || find(mth[G[x][i]])) {
				mth[G[x][i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d", &n)) {
		cnt=ans=0;
		memset(vis, -1, sizeof vis);
		memset(mth, -1, sizeof mth);
		for (int i=0;i<=n;i++) G[i].clear();
		for (int i=1;i<=n;i++) {
			scanf("%d: (%d)", &a, &m);
			while (m--)
				scanf("%d", &b), G[a].push_back(b);
		}
		for (int i=0;i<n;i++)
			memset(vis, 0, sizeof vis), ans+=find(i);
		printf("%d\n", n-ans/2);
	}
}