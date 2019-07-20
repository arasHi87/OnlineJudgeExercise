#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll B, P, M;
    while (~scanf("%lld%lld%lld", &B, &P, &M)) {
        ll ans = 1;
        ll base = B;
        while (P != 0) {
            if (P&1) ans = (ans*base)%M;
            base = (base*base)%M;
            P >>= 1;
        }
        printf("%lld\n", ans);
    }
}