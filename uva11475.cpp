#include <iostream>
#include <cstring>
using namespace std;
const int maxN=1e5+10;

char p[maxN], s[maxN];
int next[maxN];

inline void getNext(char* p, int next[]) {
    int pLen=strlen(p);
    next[0]=-1;
    int k=-1;
    int j=0;
    while (j<pLen-1) {
        if (k==-1 || p[j]==p[k]) {
            k++, j++;
            if (p[j]!=p[k]) next[j]=k;
            else next[j]=next[k];
        } else {
            k=next[k];
        }
    }
}

inline int kmpSearch(char* s, char* p, int next[]) {
    getNext(p, &next[]);
    int i=0, j=0;
    int sLen=strlen(s), pLen=strlen(p);
    while (i<sLen && j<pLen) {
        if (j==-1 || s[i]==p[j]) i++, j++;
        else j=next[j];
    }
    if (j==pLen) return i-j;
    else return -1;
}

int main() {
    string str;
    while (cin>>str) {

    }
}