#include <iostream>
#include <memory.h>
using namespace std;

int mp[55][55];
char site[4]={'N', 'E', 'S', 'W'};
int foward[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int x, y;
    cin>>x>>y;
    memset(mp, 0, sizeof mp);
    int x1, y1;
    char f[1];
    while (cin>>x1>>y1>>f) {
        bool ok=false;
        int idx=0; string s;
        int n1=x1, n2=y1;
        cin>>s;
        if (f[0]=='E') idx=1;
        else if (f[0]=='S') idx=2;
        else if (f[0]=='W') idx=3;
        for (int i=0;i<(int)s.length();i++) {
            // printf("de:%c\n", s[i]);
            if (s[i]=='R') idx=(idx+5)%4;
            else if (s[i]=='L') idx=(idx+3)%4;
            else if (s[i]=='F') {
                // printf("de:%c\n", site[idx]);
                int d1=n1, d2=n2;
                n1+=foward[idx][0];
                n2+=foward[idx][1];
                if (n1>x || n2>y || n1<0 || n2<0) {
                    // printf("de:%d %d\n", d1, d2);
                    if (!mp[d1][d2]) {
                        ok=true;
                        mp[d1][d2]=1;
                        break;
                    }
                    n1=d1, n2=d2;
                }
            }
            // printf("de:%d\n", idx);
        }
        if (ok) cout<<n1-foward[idx][0]<<" "<<n2-foward[idx][1]<<" "<<site[idx]<<" LOST"<<'\n';
        else cout<<n1<<" "<<n2<<" "<<site[idx]<<'\n';
    }
}