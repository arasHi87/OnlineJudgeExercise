#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; scanf("%lld", &n);
    while (n--) {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a<b) swap(a, b);
        if (a<c) swap(a, c);
        ll x=b*b+c*c, t=a*a;
        if (a>b+c || b<=0 || c<=0) printf("illegal triangle\n");
        else if (t==x) printf("right triangle\n");
        else if (t>x) printf("acute triangle\n");
        else printf("obtuse triangle\n");
    }
}