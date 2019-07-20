#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sav;

int main() {
    int t; cin>>t;
    while (t--) {
        sav.clear();
        int cnt=0;
        bool ok=false;
        string s; cin>>s;
        for (int i=0;i<(int)s.size();i++) {
            if (s[i]=='0') ok=true;
            sav.push_back(s[i]-'0');
            cnt+=(s[i]-'0');
        }
        if (!ok || cnt%3) cout<<"-1"<<endl;
        else {
            sort(sav.begin(), sav.end());
            for (int i=sav.size()-1;i>=0;i--) cout<<sav[i];
            cout<<'\n';
        }
    }
}