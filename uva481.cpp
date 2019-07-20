#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN=1e5+10;
const int INF=1e9+10;

int a[maxN], LIS[maxN], dp[maxN], pos[maxN], pre[maxN];

void print(int idx) {
    if (pre[idx]!=-1)
        print(pre[idx]);
    printf("%d\n", a[idx]);
}

int main() {
    int idx=1;
    while (~scanf("%d", &a[idx])) dp[idx++]=INF;
    pos[0]=-1;
    for (int i=1;i<idx;i++) {
        int p=lower_bound(dp+1, dp+idx-1, a[i])-dp;
        dp[p]=a[i];
        pos[p]=i;
        pre[i]=(p?pos[p-1]:-1);
    }
    int p=lower_bound(dp+1, dp+idx-1, INF)-dp;
    printf("%d\n-\n", p-1);
    print(pos[p-1]);
}