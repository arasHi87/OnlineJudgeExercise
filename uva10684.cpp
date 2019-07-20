#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int  num, Max=0, mss=-1;
        while (n--) {
            scanf("%d", &num);
            if (mss<0) mss=num;
            else mss+=num;
            Max=max(Max, mss);
        }
        if (Max>0) printf("The maximum winning streak is %d.\n", Max);
        else printf("Losing streak.\n");
    }
}