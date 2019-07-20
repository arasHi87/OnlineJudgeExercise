#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=200;
const int INF=0x3f3f3f3f;
struct Node {
    int x, y, z;
    Node(): x(0), y(0), z(0) {};
    Node(int _x, int _y, int _z): x(_x), y(_y), z(_z) {};
} node[maxN];
int n, x, y, z, kase=1, dp[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        int idx=1, ans=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d", &x, &y, &z);
            node[idx++]=Node(x, y, z);
            node[idx++]=Node(x, z, y);
            node[idx++]=Node(y, x, z);
            node[idx++]=Node(y, z, x);
            node[idx++]=Node(z, x, y);
            node[idx++]=Node(z, y, x);
        }
        sort(node+1, node+idx, [](Node rhs, Node lhs) {
            if (rhs.x!=lhs.x) return rhs.x<lhs.x;
            return rhs.y<lhs.y;
        });
        for (int i=1;i<idx;i++) {
            dp[i]=node[i].z;
            for (int j=1;j<i;j++)
                if (node[i].x>node[j].x && node[i].y>node[j].y && node[i].z+dp[j]>dp[i])
                    dp[i]=node[i].z+dp[j];
            if (dp[i]>ans) ans=dp[i];
        }
        printf("Case %d: maximum height = %d\n", kase++, ans);
    }
}