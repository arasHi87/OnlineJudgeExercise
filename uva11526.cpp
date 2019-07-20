#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long t, n;
    cin>>t;
    while (t--) {
        cin>>n;
        long long tmp, et, ans=0;
        for (long long i=1;i<=n;i++) {
            tmp=n/i;
            et=n/tmp;
            ans+=(et-i+1)*tmp;
            i=et;
        }
        cout<<ans<<endl;
    }
}