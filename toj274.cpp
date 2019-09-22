#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=2e5+10;
int t;
char s[maxN];
inline void readc(){
    char c=getchar(), *ch=s;
    while (c<'a' || c>'z') c=getchar();
    while (c>='a' && c<='z') *ch++=c, c=getchar();
    *ch='\0';
}
inline int readi() {
	char c=getchar(); int x=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') x=(x<<3)+(x<<1)+(c-'0'), c=getchar();
	return x;
}
inline int check(int L, int R) {
    while (L<=R)
        if (s[L++]!=s[R--]) return 0;
    return 1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    t=readi();
    while (t--) {
        readc();
        int L=0, R=strlen(s)-1;
        while (s[L]==s[R]) L++, R--;
        (L>=R || check(L+1, R) || check(L, R-1)) ? puts("YES") : puts("NO");
    }
}