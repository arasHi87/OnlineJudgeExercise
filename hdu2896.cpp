#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxN=2e6+10;
struct Node {
    Node *next[130];
    Node *fail;
    int id;
    Node() {
        memset(next, 0, sizeof next);
        fail=NULL;
        id=0;
    }
} *root;
struct Status {
    Node *tmp;
    int id;
    Status(Node *_tmp, int _id): tmp(_tmp), id(_id) {}
};
int n, m, ans;
char s[maxN];
vector<int> dic;
void build() {
    queue<Node*> q;
    Node *tmp, *cur;
    q.push(root);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
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
                q.push(cur->next[i]);
            }
        }
    }
}
void insert(char *str, int i) {
    int id;
    Node *tmp=root;
    while (*str) {
        id=*str-'a';
        if (tmp->next[id]==NULL)
            tmp->next[id]=new Node();
        str++, tmp=tmp->next[id];
    }
    tmp->id=i;
}
vector<int> query(char *str) {
    queue<Status> q;
    Node *tmp, *cur=root;
    int id;
    while (*str) {
        id=*str-'a';
        while (cur->next[id]==NULL && cur!=root)
            cur=cur->fail;
        cur=cur->next[id];
        if (cur==NULL) cur=root;
        tmp=cur;
        while (tmp!=root && tmp->id) {
            q.push(Status{tmp, tmp->id});
            dic.emplace_back(tmp->id);
            tmp->id=0;
            tmp=tmp->fail;
        }
        str++;
    }
    while (!q.empty()) {
        q.front().tmp->id=q.front().id;
        q.pop();
    }
    return dic;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    root=new Node();
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%s", s);
        insert(s, i);
    }
    build();
    scanf("%d", &m);
    for (int i=1;i<=m;i++) {
        scanf("%s", s);
        if (query(s).size()) {
            printf("web %d:", i), ans++;
            for (int j=0;j<(int)dic.size();j++)
                printf(" %d", dic[j]);
            puts("");
        }
        dic.clear();
    }
    printf("total: %d\n", ans);
}