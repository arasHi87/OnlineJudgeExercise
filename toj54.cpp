#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=1e6+10;

int h[26], t[26];

// inline int init() {
//     h[26]={0};
//     t[26]={0};
// }

int main() {
    int n;
    string s;
    while (cin>>n) {
        for (int i=1;i<=n;i++) {
            cin>>s;
            int head=s[0]-'a';        
            int tail=s[(int)s.length()-1]-'a';
            h[head]>=tail[t]?h[head]++:tail[t]++;
        }
        bool ok=true;
        for (int i=1;i<=26;i++) {
            
        }
    }
}