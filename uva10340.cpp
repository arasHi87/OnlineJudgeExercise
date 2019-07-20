#include <iostream>
using namespace std;

int main() {
    string  s, t;
    while (cin>>s>>t) {
        int sn=s.length(), tn=t.length(), idx=0;
        for (int i=0;i<tn;i++) {
            if (s[idx]==t[i]) idx++;
            if (sn==idx) break;
        }
        if (idx==sn) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
}