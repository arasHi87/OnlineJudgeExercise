#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=80;

int main() {
    int K, E, T=1;
    while (cin>>K>>E) {
        string sav[maxN][maxN];
        string exc[maxN];
        string key[maxN];
        vector<string> ans;
        for (int i=1;i<=K;i++) cin>>key[i];
        getchar();
        for (int i=1;i<=E;i++) getline(cin, exc[i]);
        for (int i=1;i<=E;i++) {
            int idx=1;
            for (int j=0;j<(int)exc[i].length();j++) {
                if (isalpha(exc[i][j])) sav[i][idx].push_back(towlower(exc[i][j]));
                else idx++;
            }
        }
        int cur=0, cnt=0;
        for (int i=1;i<=E;i++) {
            cnt=0;
            for (int j=1;j<=maxN;j++) {
                string tmp=sav[i][j];
                if (!tmp.empty()) {
                    for (int k=1;k<=K;k++) {
                        if (tmp==key[k]) cnt++;
                    }
                }
            }
            if (cnt>=cur) {
                if (cnt>cur) {ans.clear(); cur=cnt;}
                ans.push_back(exc[i]);
            }
        }
        printf("Excuse Set #%d\n", T++);
        for (auto it=ans.begin();it!=ans.end();it++) {
            cout<<*it<<'\n';
        }
        cout<<'\n';
    }
}