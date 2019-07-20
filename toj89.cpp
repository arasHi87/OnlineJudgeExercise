#include <iostream>
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define de cout<<fx<<" "<<fy<<" "<<fx1<<" "<<fy1<<endl;
using namespace std;
const int maxN=5e5+10;

int n;
int root[maxN*2];
int _rank[maxN*2];

int find(int x) {
    return (root[x]==x?x:root[x]=find(root[x]));
}

inline void init() {
    for (int i=0;i<=n*2;i++) {
        root[i]=i;
        _rank[i]=0;
    }
}

inline void unite(int x, int y) {
    if (x==y) return;
    if (_rank[x]<_rank[y]) {
        root[x]=y;
    } else {
        root[y]=x;
        if (_rank[x]==_rank[y]) _rank[x]++;
    }
}

int main() {
    IO
    int t; cin>>t;
    n=t;
    while (t--) {
        init();
        int x, y;
        string s1, s2, s3;
        cin>>s1>>s2>>s3>>x>>y;
        int x1=x+n, y1=y+n, fx=find(x), fy=find(y), fx1=find(x1), fy1=find(y1);
        if (s1[0]=='y') {
            if (s3[0]=='f') {
                de
                if (fx==fy1 || fy==fx1) cout<<"angry"<<endl;
                else {unite(fx, fy); unite(fx1, fy1);}
            } else {
                if (fx==fy || fx1==fy1) cout<<"angry"<<endl;
                else {unite(fx, fy1); unite(fx1, fy);}
            }
        } else {
            if (s3[0]=='f') {
                if (fx==fy) cout<<"yeap"<<endl;
                else cout<<"nope"<<endl;
            } else {
                if (fx==fy1 || fx1==fy) cout<<"yeap"<<endl;
                else cout<<"nope"<<endl;
            }
        }
    }
}