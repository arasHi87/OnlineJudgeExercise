#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL b, s, c, nb, ns, nc, pb, ps, pc, sum;
string opt;
bool jg(LL x) {
    LL tmp=0;
    if (b>0 && x*nb>b) tmp+=(x*nb-b)*pb;
    if (s>0 && x*ns>s) tmp+=(x*ns-s)*ps;
    if (c>0 && x*nc>c) tmp+=(x*nc-c)*pc;
    return tmp>sum;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    cin>>opt;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &b, &s, &c, &pb, &ps, &pc, &sum);
    for (int i=0;i<(int)opt.size();i++)
        if (opt[i]=='B') nb++;
        else if (opt[i]=='S') ns++;
        else nc++;
    LL L=0, R=sum+max(b, max(s, c)), mid;
    while (L<=R) {
        mid=(L+R)>>1;
        if (jg(mid)) R=mid-1;
        else L=mid+1;
    }
    printf("%lld\n", (L+R)>>1);
}