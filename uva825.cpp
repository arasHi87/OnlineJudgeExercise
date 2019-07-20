#include <iostream>
#include <memory.h>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int w, n;
        cin>>w>>n;
        int dp[100][100]={0};
        int mp[100][100]={0};
        cin.ignore();
        for (int i=1;i<=w;i++) {
            int j;
            string line;
            getline(cin, line);
            stringstream ss(line);
            ss>>j;
            // printf("%d\n", j);
            while (ss>>j) mp[i][j]=1;
        }
        dp[1][1]=1;
        for (int i=1;i<=w;i++)
            for (int j=1;j<=n;j++) {
                if (mp[i][j]) continue;
                if (i>1) dp[i][j]+=dp[i-1][j];
                if (j>1) dp[i][j]+=dp[i][j-1];
            }
        cout<<dp[w][n]<<'\n';
        if (t) cout<<'\n';
    }
}