#include <iomanip>
#include <cstring>
#include <iostream>
using namespace std;
const int maxN=2e3+10;
const int INF=0x3f3f3f3f;
int n, k;
int a[maxN], b[maxN], dp[maxN];
int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    cin>>n;
    while (n--) {
        cin>>k;
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=k;i++) cin>>a[i];
        for (int i=1;i<k;i++)  cin>>b[i];
        dp[1]=a[1];
        for (int i=2;i<=k;i++)
            dp[i]+=min(dp[i-1]+a[i], dp[i-2]+b[i-1]);
        int H=8, M=0, S=dp[k];
        M+=S/60, S%=60, H+=M/60, M%=60;
        cout<<setw(2)<<setfill('0')<<H<<':'<<setw(2)<<setfill('0')<<M<<':'<<setw(2)<<setfill('0')<<S<<' ';
        if (H>12) cout<<"pm"<<'\n';
        else cout<<"am"<<'\n';
    }
}