#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e6+10;
struct Node {
    Node *next[26];
    Node *fail;
    int tag;
    Node() {
        memset(next, 0, sizeof next);
        fail=NULL;
        tag=0;
    }
} *root;
int t, n;
char s[maxN];
void build() {
    queue<Node*> q;
    q.push(root);
    Node *tmp, *cur;
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        tmp=NULL;
        for (int i=0;i<26;i++) {
            if (cur->next[i]!=NULL) {
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
                q.push(cur->next[i]);
            }
        }
    }
}
void insert(char *str) {
    int id;
    Node *tmp=root;
    while (*str) {
        id=*str-'a';
        if (tmp->next[id]==NULL)
            tmp->next[id]=new Node();
        str++, tmp=tmp->next[id];
    }
    tmp->tag++;
}
int query(char *str) {
    Node *tmp, *cur=root;
    int cnt=0, id;
    while (*str) {
        id=*str-'a';
        while (cur->next[id]==NULL && cur!=root)
            cur=cur->fail;
        cur=cur->next[id];
        if (cur==NULL) cur=root;
        tmp=cur;
        while (tmp!=root && tmp->tag!=-1) {
            cnt+=tmp->tag;
            tmp->tag=-1;
            tmp=tmp->fail;
        }
        str++;
    }
    return cnt;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        root=new Node();
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%s", s);
            insert(s);
        }
        build();
        scanf("%s", s);
        printf("%d\n", query(s));
    }
}