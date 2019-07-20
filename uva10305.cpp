#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
const int maxN=105;

int n, m;
int mp[maxN][maxN];
int indegree[maxN];
int ans[maxN];

void topo() {
    queue<int> pth;
    int cnt=1;
    for (int i=1;i<=n;i++) 
        if (indegree[i]==0)
            pth.push(i);
    while (!pth.empty()) {
        int tmp=pth.front(); pth.pop();
        ans[cnt++]=tmp;
        for (int i=1;i<=n;i++) 
            if (mp[tmp][i]!=0)
                if (--indegree[i]==0)
                    pth.push(i);
    }
    cout<<ans[1];
    for (int i=2;i<=n;i++)
        cout<<" "<<ans[i];
    puts("");
}

int main() {
    while (cin>>n>>m) {
        if (n==0 && m==0) return 0;
        memset(mp, 0, sizeof mp);
        memset(indegree, 0, sizeof indegree);
        memset(ans, 0, sizeof ans);
        while (m--) {
            int a, b; cin>>a>>b;
            mp[a][b]=1; indegree[b]++;
        }
        topo();
    }
}