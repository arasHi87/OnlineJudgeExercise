#include <iostream>
#include <memory.h>
using namespace std;
const int maxN=1e3+10;

int main() {
    int n; cin>>n;
    while (n--) {
        int x; cin>>x;
        bool vis[x]={false};
        int can=0, no=0;
        while (x--) {
            int a, b;
            char c;
            cin>>c>>a>>b;
            if (c=='c') vis[a]=vis[b]=true;
            else {
                if (vis[a] && vis[b]) can++;
                else no++;
            }
        }
        printf("%d,%d\n\n", can, no);
    }
}