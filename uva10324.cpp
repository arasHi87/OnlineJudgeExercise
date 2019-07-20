#include <iostream>
using namespace std;
const int maxN=1e6+10;

int cnt[maxN]={0};

int main() {
    string s;
    int t=1;
    while (cin>>s) {
        int sum=0, n;
        for (int i=1;i<(int)s.length();i++) {
            if (s[i]!=s[i-1]) sum++;
            cnt[i]=sum;
        }
        cin>>n;
        printf("Case %d:\n", t++);
        for (int i=1;i<=n;i++) {
            int a, b;
            cin>>a>>b;
            if (cnt[a]!=cnt[b]) cout<<"No"<<'\n';
            else cout<<"Yes"<<'\n';
        }
    }
}