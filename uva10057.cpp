#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=1e6+10;

int s[maxN];

int main() {
    int n;
    while (cin>>n) {
        for (int i=0;i<n;i++) cin>>s[i];
        sort(s, s+n);
        int v=s[(n-1)>>1], cnt=0;
        for (int i=0;i<n;i++) {
            cnt+=(v==s[i] || s[i]==s[n>>1]);
        }
        printf("%d %d %d\n", v, cnt, s[n>>1]-v+1);
    }
}