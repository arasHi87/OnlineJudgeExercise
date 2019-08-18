#include <cstring>
#include <iostream>
using namespace std;
const int maxN=1e6+10;
int t, n;
char x[maxN], y[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while (t--) {
        cin>>x>>n;
        while (n--) {
            cin>>y;
            if (strstr(x, y)==NULL) cout<<'n'<<'\n';
            else cout<<'y'<<'\n';
        }
    }
}