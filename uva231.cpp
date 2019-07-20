#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
const int INF=1e9+10;

int dp[maxN];
vector<int> a;

int main() {
    int kase=1;
    while (1) {
        int num, idx=1;
        a.clear();
        scanf("%d", &num);
        if (num==-1)
            return 0;
        a.push_back(num);
        while (scanf("%d", &num) && num!=-1)
            a.push_back(num), idx++;
        reverse(a.begin(), a.end());
        for (int i=0;i<idx;i++)
            dp[i]=INF;
        for (int i=0;i<(int)a.size();i++) {
            int pos=upper_bound(dp, dp+idx, a[i])-dp;
            dp[pos]=a[i];
        }
        if (kase!=1) puts("");
        printf("Test #%d:\n", kase++);
        printf("  maximum possible interceptions: %ld\n", lower_bound(dp, dp + idx - 1, INF) - dp);
        // cout<<lower_bound(dp, dp+idx, INF)-dp<<'\n';
    }
}