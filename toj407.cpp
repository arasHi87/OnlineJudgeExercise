#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxN=2e5+3e4+10;

int t, p, q, k, u, v, cnt=0;
int vis[maxN];
int match[maxN];
vector<int> edges[maxN];

bool dfs(int x) {
    vis[x]=cnt;
    for (auto it:edges[x]) {
        if (match[it]==-1 || (vis[match[it]]!=cnt && dfs(match[it]))) {
            match[it] = x;
            match[x]  = it;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &p, &q, &k);
        int ans=0, limit=p+q;
        // memset(match, -1, sizeof match);
        for (int i=1;i<=limit;i++) edges[i].clear(), match[i]=-1;
        while (k--) {
            scanf("%d%d", &u, &v);
            v += p;
            edges[u].emplace_back(v);
            edges[v].emplace_back(u);
        }
        cnt=0;
        for (int i=1;i<=limit;i++) {
            if (match[i]==-1) {
                cnt++;
                if (dfs(i)) ans++;
            }
        }
        printf("%d\n", ans);
    }
}