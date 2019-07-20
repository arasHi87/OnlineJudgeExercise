#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node *lc, *rc;
    int tag, bl, br, cor; // 0->no, 1->blue, 2->yellow
    Node():lc(NULL), rc(NULL), bl(2), br(2), cor(2), tag(0){};
} *root=new Node();
void inline push(Node *seg) {
    
}