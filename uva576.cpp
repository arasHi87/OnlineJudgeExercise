#include <iostream>
#include <memory.h>
using namespace std;

int mp[210];
int size[3];

int main() {
    memset(mp, 0, sizeof mp);
    mp[(int)'a'-'a']=mp[(int)'e'-'a']=mp[(int)'i'-'a']=mp[(int)'o'-'a']=mp[(int)'u'-'a']=mp[(int)'y'-'a']=1;
    string s;
    while (getline(cin, s)) {
        if (s=="e/o/i") break;
        int idx=0;
        memset(size, 0, sizeof size);
        for (int i=0;i<(int)s.length();i++) {
            if (s[i]=='/') idx++;
            else if (i==0 || !mp[(int)s[i-1]-'a']) size[idx]+=mp[(int)s[i]-'a'];
        }
        // printf("%d %d %d\n", size[0], size[1], size[2]);
        if (size[0] != 5) puts("1");
        else if (size[1] != 7) puts("2");
        else if (size[2] != 5) puts("3");
        else puts("Y");
    }
}