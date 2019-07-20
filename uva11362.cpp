#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
const long long prime_mod=1e9+7;
const long long prime=0xdefaced;
typedef long long LL;

LL h[15], hb[15];
string s;
vector<int> v;
set<LL> ans;

inline void hash_init(int len) {
    hb[0]=1;
    for (int i=1;i<=len;i++) {
        h[i]=(h[i-1]*prime+s[i-1])%prime_mod;
        hb[i]=(hb[i-1]*prime)%prime_mod;
    }
}

inline LL get_hash(int l, int r) {
    return (h[r+1]-(h[l]*hb[r-l+1])%prime_mod+prime_mod)%prime_mod;
}

int main() {
    int n, k;
    cin>>n;
    while (n--) {
        cin>>k;
        while (k--) {
            cin>>s;
            hash_init();
        }
    }
}