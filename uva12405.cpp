#include <iostream>
#include <memory.h>
using namespace std;

char s[105];
int ck[105];

int main() {
    int t;
    cin>>t;
    for (int j=1;j<=t;j++) {
        int n, ans=0;
        cin>>n;
        memset(ck, 0, sizeof ck);
        for (int i=1;i<=n;i++) cin>>s[i];
        for (int i=1;i<=n;i++) {
            if (s[i]=='.' && !ck[i]) {
                if (s[i+2]=='.') ck[i]=1, ck[i+1]=1, ck[i+2]=1;
                else ck[i]=1, ck[i+1]=1;
                ans++;
            }
        }
        printf("Case %d: %d\n", j, ans);
    }
}