#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxN=1e4+10;

int n, m, p, cnt[maxN][maxN], kase=1;
vector<int> a, b;

int LCS() {
    // int ans=0;
    int nx=a.size();
    int ny=b.size();
    for (int i=0;i<=max(nx, ny);i++) cnt[i][0]=0;
    for (int i=1;i<nx;i++) {
        for (int j=1;j<ny;j++) {
            if (a[i]==b[j]) cnt[i][j]=cnt[i-1][j-1]+1;
            else cnt[i][j]=max(cnt[i-1][j], cnt[i][j-1]);
            // ans=max(ans, cnt[i][j]);
        }
    }
    return cnt[nx-1][ny-1];
}

int main() {
    while (~scanf("%d%d", &n, &m) && n && m) {
        a.clear(), b.clear();
        a.push_back(0), b.push_back(0);
        for (int i=1;i<=n;i++) scanf("%d", &p), a.push_back(p);
        for (int i=1;i<=m;i++) scanf("%d", &p), b.push_back(p);
        printf("Twin Towers #%d\n", kase++);
        printf("Number of Tiles : %d\n\n", LCS());
    }
}