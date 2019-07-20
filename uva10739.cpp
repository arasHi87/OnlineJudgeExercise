#include <iostream>
#include <memory.h>
using namespace std;
const int maxN=1e3+10;

long long dp[maxN][maxN];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin>>n;
    for (int k=1;k<=n;k++) {
        memset(dp, 0, sizeof dp);
        string s;
        cin>>s;
        int len=s.length();
        for (int i=len-1;i>=0;i--) {
            for (int j=i+1;j<len;j++) {
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j-1], min(dp[i+1][j], dp[i][j-1]))+1;
            }
        }
        cout<<"Case "<<k<<": "<<dp[0][len-1]<<endl;
    }
}