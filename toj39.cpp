#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=479001599;
LL ans=1;
char opt[20];
LL c2i() {
    int len=strlen(opt); LL tmp=0;
    for (int i=0;i<len;i++)
        tmp=tmp*10+(opt[i]-'0');
    return tmp;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s", opt)) {
        if (opt[0]=='%') printf("%ld\n", ans), ans=1;
        else {
            ans*=c2i();
            ans%=mod;
        }
    }
}