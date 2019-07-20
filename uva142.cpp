#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct window {
    char n;
    pair<int, int> l;
    pair<int, int> r;
} W[1000];

struct icon {
    pair<int, int> p;
} I[1000];

inline bool cmp(const window lhs, const window rhs) {
    if (lhs.l!=rhs.l) return lhs.l<rhs.l;
}

vector<pair<int, int>> M;

int main() {
    char c[1];
    int a, b, c, d;
    int i_idx=0, w_idx=0;
    while (cin>>c) {
        if (c[0]=='#') break;
        if (c[0]=='I') {
            int x, y;
            I[i_idx].p=make_pair(x, y);
            i_idx++;
        } else if (c[0]=='W') {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            W[w_idx].l=make_pair(x1, y1);
            W[w_idx].r=make_pair(x2, y2);
            w_idx++;
        } else if (c[0]=='M') {
            int x, y;
            cin>>x>>y;
            M.push_back(make_pair(x, y));
        }
    }
    sort(I, I+i_idx);
    sort(W, W+w_idx, cmp);
    bool ok=false;
    for (auto it=M.begin();it!=M.end();it++) {
        set<int> x1; set<int> y1; set<int> fp;
        int x=(*it).first, y=(*it).second;
        int pos1=upper_bound(W, W+w_idx, x)-W;
        int pos2=lower_bound(W, W+w_idx, y)-W;
        for (int i=pos1;i<=w_idx;i++) x1.insert(i);
        if (W[pos2].l.second>y) for (int i=0;i<pos2;i++) y1.insert(i);
        set_intersection(x1.begin(), x1.end(), y1.begin(), y1.end(), inserter(fp, fp.begin()));
        if (fp.empty()) break;
        for (int i=0;i<fp.size();i++) {
            if (W[i].r.first>=x && W[i].r.second<=y) {
                cout<<char(i+'A')<<endl;
                ok=true;
                break;
            }
        }
        if (!ok) {
            int pos=upper_bound(I, I+i_idx, x)-I;
        }
    }
}