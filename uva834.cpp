#include <iostream>
#include <vector>
using namespace std;

vector<int> sav;

int main() {
    int a, b, tmp=0;
    while (cin>>b>>a) {
        sav.clear();
        while (a!=0) {
            sav.push_back(b/a);
            tmp=a;
            a=b%a;
            b=tmp;
        }
        printf("[%d;", sav[0]);
        for (int i=1;i<(int)sav.size();i++)
            if (i!=(int)sav.size()-1) printf("%d,", sav[i]);
            else printf("%d", sav[i]);
        puts("]");
    }
}