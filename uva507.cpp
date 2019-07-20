#include <iostream>
using namespace std;
const int maxN=2e5+10;

int a[maxN];
    
int main() {
    int n, k;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &k);
        for (int i=1;i<k;i++) scanf("%d", a+i);
        int l=0, r=0, maxSum=0, sum=0, x=0;
        for (int i=1;i<k;i++) {
            sum += a[i];
            if (sum>maxSum || (sum==maxSum && i-x > r-l)) r=i, l=x, maxSum=sum;
            else if (sum<0) sum=0, x=i;
        }
        if (maxSum==0) printf("Route %d has no nice parts\n", i);
        else  printf("The nicest part of route %d is between stops %d and %d\n", i, l+1, r+1);
    }
}