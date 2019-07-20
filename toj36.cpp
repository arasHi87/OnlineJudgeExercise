#include <iostream>
using namespace std;
typedef long long ll;

inline ll qpow(ll a, ll b, ll c) {
    ll ans=1; a%=c;
    while (b) {
        if (b&1) ans=ans*a%c;
        a=a*a%c;
        b>>=1;
    }
    return ans%c;
}

int main() {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", qpow(a, b, c));
}