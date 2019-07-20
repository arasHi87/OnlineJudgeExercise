#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxN=205;

inline int myget(char s[]) {
    char c;
    int i=0;
    while ((c=getchar()) && c!=EOF && c!='\n')
        s[i++]=c;
    s[i]='\0';
    return i>0 || c!=EOF;
}

int main() {
    char s[maxN];
    while (myget(s)) {
        int cnt=0, len=strlen(s);
        for (int i=0;i<len;i++) {
            if (isdigit(s[i])) cnt+=(s[i]-'0');
            else if (s[i]=='!') putchar('\n');
            else {
                for (int j=cnt;j>0;j--)
                    putchar((s[i] == 'b') ? ' ' : s[i]);
                cnt=0;
            }
        }
        putchar('\n');
    }
}