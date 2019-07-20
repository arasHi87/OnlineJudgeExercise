#include <iostream>
using namespace std;
const int maxN=1e6;

string data[maxN], item[maxN];
int pos[maxN];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int idx=1;
        while (cin>>pos[idx++]) if (cin.get()=='\n') break;
        for (int i=1;i<idx;i++) cin>>data[i];
        for (int i=1;i<idx;i++) item[pos[i]]=data[i];
        for (int i=1;i<idx;i++) cout<<item[i]<<'\n';
        if (t) cout<<'\n';
    }
}