#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10, maxM=50+5;
struct Node {
    Node *next[26];
    Node *fail;
    vector<int> id;
    Node() {
        memset(next, 0, sizeof next);
        fail=NULL;
        id.emplace_back(0);
    }
} *root;
int t, n;
char s[maxN], p[maxM];
int ans[1010];
void build() {
    queue<Node*> Q;
    Node *tmp, *cur;
    Q.push(root);
    while (!Q.empty()) {
        cur=Q.front();
        Q.pop();
        tmp=NULL;
        for (int i=0;i<26;i++) {
            if (cur->next[i]) {
                if (cur==root) cur->next[i]->fail=root;
                else {
                    tmp=cur->fail;
                    while (tmp!=NULL && tmp->next[i]==NULL)
                        tmp=tmp->fail;
                    if (tmp==NULL)
                        cur->next[i]->fail=root;
                    else
                        cur->next[i]->fail=tmp->next[i];
                }
                Q.push(cur->next[i]);
            }
        }
    }
}
inline void insert(char *key, int i) {
    int id;
    Node *tmp=root;
    while (*key) {
        id=*key-'a';
        if (tmp->next[id]==NULL)
            tmp->next[id]=new Node();
        key++, tmp=tmp->next[id];
    }
    tmp->id.emplace_back(i);
}
void query(char *key) {
    Node *tmp, *cur=root;
    int id;
    while (*key) {
        id=*key-'a';
        while (cur->next[id]==NULL && cur!=root)
            cur=cur->fail;
        cur=cur->next[id];
        if (cur==NULL) cur=root;
        tmp=cur;
        while (tmp!=root && tmp->id.size()) {
            for (int i=1;i<tmp->id.size();i++)
                ans[tmp->id[i]]=1;
            tmp->id.clear();
            tmp=tmp->fail;
        }
        key++;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        root=new Node();
        memset(ans, 0, sizeof ans);
        scanf("%s%d", s, &n);
        for (int i=1;i<=n;i++) {
            scanf("%s", p);
            insert(p, i);
        }
        build(), query(s);
        for (int i=1;i<=n;i++)
            puts(ans[i] ? "y" : "n");
    }
}