#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=1e6+10;

int prm[maxN],
    vis[maxN],
    nmb[maxN],
    sum[maxN];

int main() {
    int tot=0;
    memset(vis, 0, sizeof vis);
    memset(nmb, 0, sizeof nmb);
    for (int i=2;i<=maxN;i++) {
        if (!vis[i])
            prm[++tot]=i, 
    }
}