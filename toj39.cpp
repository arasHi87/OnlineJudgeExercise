#include <bits/stdc++.h>
using namespace std;
const int MOD=479001599;

inline int change(string s) {
    int ans=0;
    for (int i=0;i<(int)s.size();i++) {
        ans=ans*10+s[i];
    }
    return ans;
}

int main() {
    string s;
    long long cnt=1;
    while (scanf("%s", s.c_str())) {
        if (s=="%") {printf("%lld\n", cnt); cnt=1;}
        else cnt=cnt*change(s)%MOD;
    }
}