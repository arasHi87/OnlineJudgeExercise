#include <cstdio>
using namespace std;
int a, b, c;
int main() {
    scanf("%d", &c);
    while(~scanf("%d%d", &a, &b)) {
        while((a%=b)&&(b%=a));
        printf("%d\n", a+b);
    }
}