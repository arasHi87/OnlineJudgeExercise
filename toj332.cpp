#include <iostream>
#define endl '\n'
using namespace std;
const long long MOD=1e8+7;
typedef long long ll;

inline ll qpow(ll a, ll b) {
    ll bse=a, ans=1;
    while (b) {
        if (b&1) ans=ans*bse%MOD;
        bse=bse*bse%MOD;
        b>>=1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    ll x, tmp1=1, tmp2=1;
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        cin>>x;
        tmp1=tmp1*x%MOD;
    }
    for (int i=1;i<=n;i++) {
        cin>>x;
        tmp2=tmp2*x%MOD;
    }
    cout<<(qpow(tmp1, n)*qpow(tmp2, m)%MOD+MOD)%MOD<<endl;
}