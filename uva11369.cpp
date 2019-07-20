#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=2e4+10;

int p[maxN];

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>p[i];
        sort(p+1, p+1+n);
        int ans=0;
        while (n-2>0) {
            ans+=p[n-2];
            n-=3;
        }
        // for (int i=n;i>=1;i--) ans+=p[i];
        cout<<ans<<'\n';
    }
}