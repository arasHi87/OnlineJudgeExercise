#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e2+10;
int n, m, x, y, ans=0, cnt=0;
int G[maxN][maxN];
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		G[x][y]=1;
	}
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				G[i][j]|=G[i][k]&G[k][j];
			}
		}
	}
	for (int i=1;i<=n;i++) {
		cnt=0;
		for (int j=1;j<=n;j++) {
			cnt+=(G[i][j]+G[j][i]);
		}
		if (cnt==n-1) ans++;
	}
	printf("%d\n", ans);
}