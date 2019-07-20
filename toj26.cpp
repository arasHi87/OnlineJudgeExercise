#include <iostream>
#include <memory.h>
#include <algorithm>
#define IO ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int maxN=3005;

int dp[maxN][maxN];

int main() {
    IO
    int T; cin>>T;
    while (T--) {
        string s; cin>>s;
        string a(s);
        reverse(a.begin(), a.end());
        int len=s.length();
        for (int i=1;i<=len;i++)
            for (int j=1;j<=len;j++)
                if (s[i-1]==a[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        cout<<dp[len][len]<<endl;
    }
}