#include <bits/stdc++.h>
using namespace std;
struct Node {
    map<string, Node*> nxt;
    Node *fa;
} *root;
inline void build(Node *cur, string &str) {
    cur->nxt[str]=new Node();
    cur->nxt[str]->fa=cur;
}
inline void print(Node *cur) {
    for (auto it=cur->nxt.begin();it!=cur->nxt.end();it++)
        cout<<it->first<<'\n';
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    char ch;
    string cmd, path;
    root=new Node();
    root->fa=root;
    Node *cur=root;
    while (cin>>cmd) {
        cin.get(), path.clear();
        if (cmd!="ls")
            while ((ch=cin.get())!='\n')
                if (ch!='\\')
                    path.push_back(ch);
        if (cmd=="ls") print(cur);
        else if (cmd=="touch" || cmd=="mkdir") build(cur, path);
        else {
            int idx=0;
            string tmp;
            if (path[0]=='/') cur=root, idx=1;
            for (;idx<(int)path.length();idx++) {
                // if (path[idx]=='\\') continue;
                if (path[idx]!='/') tmp.push_back(path[idx]);
                if (path[idx]=='/' || idx==(int)path.size()-1) {
                    if (tmp==".") cur=cur;
                    else if (tmp=="..") cur=cur->fa;
                    else cur=cur->nxt[tmp];
                    tmp.clear();
                }
            }
        }
    }
}